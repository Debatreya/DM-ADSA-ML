# 1. Load the Iris dataset and display key columns
df = pd.read_csv('./iris.csv')
X = df['SepalLengthCm'].values.reshape(-1, 1)  # Using SepalLength as input
y = df['PetalLengthCm'].values.reshape(-1, 1)  # Using PetalLength as output

# 2. User inputs the range of input and polynomial degree
# The range for input X
print("Select a range for input variable SepalLengthCm (e.g., 4.3 to 7.9)")
min_range = float(input("Enter the minimum value for SepalLengthCm: "))
max_range = float(input("Enter the maximum value for SepalLengthCm: "))

# Filter the data based on user-defined range
X_filtered = X[(X >= min_range) & (X <= max_range)]
y_filtered = y[(X >= min_range) & (X <= max_range)]

# User inputs the degree of the polynomial
degree = int(input("Enter the degree of the polynomial regression: "))

# Function to normalize features (feature scaling)
def normalize_features(X):
    return (X - np.mean(X)) / np.std(X)

# Normalize the features
X_filtered_normalized = normalize_features(X_filtered)

# 3. Implement the polynomial feature generator
def generate_polynomial_features(X, degree):
    X_poly = np.ones((X.shape[0], 1))  # Bias term (ones)
    for d in range(1, degree + 1):
        X_poly = np.hstack((X_poly, (X**d).reshape(-1, 1)))  # Reshape X**d to 2D
    return X_poly

# Generate polynomial features based on user input
X_poly = generate_polynomial_features(X_filtered_normalized, degree)

# Initialize theta (weights)
theta = np.zeros((X_poly.shape[1], 1))

# Gradient Descent Implementation
def gradient_descent(X, y, theta, learning_rate, iterations):
    m = len(y)
    cost_history = []
    
    for i in range(iterations):
        # Predict the y values
        y_pred = X.dot(theta)
        
        # Compute gradient
        gradient = (1/m) * X.T.dot(y_pred - y)
        
        # Update theta
        theta = theta - learning_rate * gradient
        
        # Compute the cost for convergence
        cost = (1/(2*m)) * np.sum((y_pred - y)**2)
        cost_history.append(cost)
        
    return theta, cost_history

# Setting hyperparameters for gradient descent
learning_rate = 0.01
iterations = 1000

# Run gradient descent and optimize theta
theta_optimized, cost_history = gradient_descent(X_poly, y_filtered, theta, learning_rate, iterations)

# Plot cost history to see the convergence
plt.plot(range(iterations), cost_history)
plt.xlabel('Iterations')
plt.ylabel('Cost')
plt.title('Cost History During Gradient Descent')
plt.show()

# Display the optimized theta values
print("Optimized theta values (polynomial coefficients):", theta_optimized)

# Predict y values based on optimized theta
y_pred = X_poly.dot(theta_optimized)

# 3. Test for optimal value using the Iris data: Plot actual vs predicted values
plt.scatter(X_filtered_normalized, y_filtered, c