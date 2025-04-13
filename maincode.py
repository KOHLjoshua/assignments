from flask import Flask, render_template, request, redirect, url_for, session, flash
from datetime import datetime
from collections import deque

app = Flask(__name__)
app.secret_key = 'your_secret_key_here'
app.config['SESSION_TYPE'] = 'filesystem'

# Data Structures implementation from linked lists to stacks to queues.
class CustomerNode:
    def __init__(self, customer_data):
        self.data = customer_data
        self.next = None

class CustomerLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0
        self.account_map = {}
    
    def add_customer(self, customer_data):
        new_node = CustomerNode(customer_data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
        self.account_map[customer_data['accountNo']] = new_node
        self.size += 1
    
    def find_customer(self, account_no):
        return self.account_map.get(account_no, None)

class TransactionStack:
    def __init__(self):
        self.stack = []
    
    def push(self, amount, timestamp):
        if len(self.stack) < 50:
            self.stack.append((amount, timestamp))
        else:
            self.stack.pop(0)
            self.stack.append((amount, timestamp))
    
    def get_transactions(self):
        return reversed(self.stack)

class TransactionQueue:
    def __init__(self):
        self.queue = deque()
    
    def enqueue(self, transaction):
        self.queue.append(transaction)
    
    def dequeue(self):
        if self.queue:
            return self.queue.popleft()
        return None

# Initialize some data for customers and pending transactions for only admins.
customers = CustomerLinkedList()
pending_transactions = TransactionQueue()

# below is the data intializesd in the bank
sample_customers = [
    {
        'accountNo': 12341,
        'lastName': "ceo KOHL",
        'firstName': "CLUB 17",
        'address': "AMuDAT",
        'phone': "077898008",
        'email': "rollrolck890@gmail.com",
        'balance': 57,
        'pin': 1111,
        'transactions': TransactionStack(),
        'is_admin': True
    },
    {
        'accountNo': 12342,
        'lastName': "JEREMY",
        'firstName': "JOSH",
        'address': "Bukoto",
        'phone': "0761959786",
        'email': "jeremynigas@gmail.com",
        'balance': 36,
        'pin': 2222,
        'transactions': TransactionStack(),
        'is_admin': False
    }
]

for customer in sample_customers:
    customers.add_customer(customer)

# routes created for each page. these routes help access the different methods from the class.
@app.route('/')
def index():
    return render_template('index.html')

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        new_customer = {
            'lastName': request.form['lastName'],
            'firstName': request.form['firstName'],
            'address': request.form['address'],
            'phone': request.form['phone'],
            'email': request.form['email'],
            'balance': 0,
            'pin': int(request.form['pin']),
            'transactions': TransactionStack(),
            'is_admin': False
        }
        
        #this is for creating a new account number for the newbie.
        last_account = customers.head
        while last_account and last_account.next:
            last_account = last_account.next
        new_customer['accountNo'] = last_account.data['accountNo'] + 1 if last_account else 12345
        
        customers.add_customer(new_customer)
        flash('Registration successful!', 'success')
        return redirect(url_for('login'))
    
    return render_template('register.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        try:
            account_no = int(request.form['accountNo'])
            pin = int(request.form['pin'])
        except ValueError:
            flash('Invalid account number or PIN format', 'danger')
            return redirect(url_for('login'))
        
        customer_node = customers.find_customer(account_no)
        if not customer_node or customer_node.data['pin'] != pin:
            flash('Invalid account number or PIN', 'danger')
            return redirect(url_for('login'))
        
        session['account_no'] = account_no
        if customer_node.data['is_admin']:
            return redirect(url_for('admin_dashboard'))
        return redirect(url_for('user_dashboard'))
    
    return render_template('login.html')

@app.route('/dashboard')
def user_dashboard():
    if 'account_no' not in session:
        return redirect(url_for('login'))
    
    customer_node = customers.find_customer(session['account_no'])
    if not customer_node:
        session.pop('account_no', None)
        return redirect(url_for('login'))
    
    return render_template('dashboard.html', customer=customer_node.data)

@app.route('/transactions')
def view_transactions():
    if 'account_no' not in session:
        return redirect(url_for('login'))
    
    customer_node = customers.find_customer(session['account_no'])
    if not customer_node:
        session.pop('account_no', None)
        return redirect(url_for('login'))
    
    transactions = customer_node.data['transactions'].get_transactions()
    return render_template('transactions.html', transactions=transactions)

@app.route('/deposit', methods=['POST'])
def deposit():
    if 'account_no' not in session:
        return redirect(url_for('login'))
    
    try:
        amount = int(request.form['amount'])
    except ValueError:
        flash('Invalid amount', 'danger')
        return redirect(url_for('user_dashboard'))
    
    if amount <= 0:
        flash('Amount must be positive', 'danger')
        return redirect(url_for('user_dashboard'))
    
    customer_node = customers.find_customer(session['account_no'])
    customer_node.data['balance'] += amount
    timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    customer_node.data['transactions'].push(amount, timestamp)
    flash(f'Deposit of {amount} was successful', 'success')
    return redirect(url_for('user_dashboard'))

@app.route('/withdraw', methods=['POST'])
def withdraw():
    if 'account_no' not in session:
        return redirect(url_for('login'))
    
    try:
        amount = int(request.form['amount'])
    except ValueError:
        flash('Invalid amount', 'danger')
        return redirect(url_for('user_dashboard'))
    
    customer_node = customers.find_customer(session['account_no'])
    if amount <= 0:
        flash('Amount must be positive', 'danger')
    elif amount > customer_node.data['balance']:
        flash('Insufficient balance', 'danger')
    else:
        customer_node.data['balance'] -= amount
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        customer_node.data['transactions'].push(-amount, timestamp)
        flash(f'Withdrawal of {amount} was successful', 'success')
    
    return redirect(url_for('user_dashboard'))

@app.route('/admin')
def admin_dashboard():
    if 'account_no' not in session:
        return redirect(url_for('login'))
    
    customer_node = customers.find_customer(session['account_no'])
    if not customer_node or not customer_node.data['is_admin']:
        return redirect(url_for('user_dashboard'))
    
    return render_template('admin.html', queue_length=len(pending_transactions.queue))

@app.route('/admin/process', methods=['POST'])
def process_transactions():
    if 'account_no' not in session:
        return redirect(url_for('login'))
    
    customer_node = customers.find_customer(session['account_no'])
    if not customer_node or not customer_node.data['is_admin']:
        return redirect(url_for('user_dashboard'))
    
    transaction = pending_transactions.dequeue()
    if not transaction:
        flash('No pending transactions', 'info')
        return redirect(url_for('admin_dashboard'))
    
    account_no, amount = transaction
    target_node = customers.find_customer(account_no)
    
    if not target_node:
        flash(f'Account {account_no} not found', 'danger')
        return redirect(url_for('admin_dashboard'))
    
    if amount > 0:  # Deposit
        target_node.data['balance'] += amount
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        target_node.data['transactions'].push(amount, timestamp)
        flash(f'Deposited {amount} to account {account_no}', 'success')
    else:  # Withdrawal
        if target_node.data['balance'] < abs(amount):
            flash(f'Insufficient balance in account {account_no}', 'danger')
        else:
            target_node.data['balance'] += amount  # amount is negative
            timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            target_node.data['transactions'].push(amount, timestamp)
            flash(f'Withdrew {-amount} from account {account_no}', 'success')
    
    return redirect(url_for('admin_dashboard'))

@app.route('/logout')
def logout():
    session.pop('account_no', None)
    flash('You have been logged out. KALE TUNADAMU', 'info')
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)