import numpy as np

# Here we will implement the logistic regression model

# Cross entropy loss function
# L = -1/N * sum(y_i * log(y_hat_i) + (1 - y_i) * log(1 - y_hat_i))
# where y_hat_i = sigmoid(w * x_i + b) OR y_hat = sigmoid(X * w) where X is the matrix of input data with an extra column of 1s
# Therefore: L = -1/N * sum(Y * log(sig(X * w)) + (1 - Y) * log(1 - sig(X * w))) // Matrix Form

# After calculating the loss function, we will update the weights and bias using the gradient descent algorithm

# Gradient of the loss function
# W(initial) = [random values] // (Wo = b), W1, W2, W3, ..., Wn
# dL/dw = -1/N * np.dot(X.T, (Y - sig(X * w))) // Matrix Form

# Update the weights
# W(new) = W(initial) - learning_rate * dL/dw




# Note: Derivative of Sigmod function is f'(x) = f(x) * (1 - f(x))

# Sigmoid function
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def Logist(X, y, lr = 0.01, epochs = 1000):
    X = np.insert(X, 0, 1, axis=1) # Insert a column of 1s at the beginning of the input data
    weights = np.ones(X.shape[1]) # Initialize the weights with 1s
    # Learning Rate is defined

    for i in range(epochs):
        y_hat = sigmoid(np.dot(X, weights)) # Calculate the predicted values
        dw = -(1/X.shape[0]) * np.dot((y - y_hat), X) # Calculate the gradient of the loss function
        weights = weights - lr * dw

    return weights[1:], weights[0] # Return the weights and bias