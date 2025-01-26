import numpy as np

class GD_Regresser:
    # Gradient Descent for Simple Linear Regression
    def __init__(self, learning_rate=0.01, epochs=1000):
        self.learning_rate = learning_rate
        self.epochs = epochs
        self.m = None
        self.b = None

    def fit(self, X, y):
        self.m = 0
        self.b = 0
        for _ in range(self.epochs):
            self.m, self.b = self.gradient_descent(X, y, self.m, self.b)

        return self.m, self.b

    def predict(self, X):
        return self.m * X + self.b
    
    def gradient_descent(self, X, y, m, b):
        n = len(X) # n = 1 for simple linear regression
        m_gradient = 0
        b_gradient = 0
        for i in range(n):
            m_gradient += -2 * (y[i] - (m * X[i] + b)) * X[i] # Derivative of m
            b_gradient += -2 * (y[i] - (m * X[i] + b)) # Derivative of b
        m -= (m_gradient / n) * self.learning_rate
        b -= (b_gradient / n) * self.learning_rate
        return m, b
    
    # R^2 test to evaluate the model
    # R^2 = 1 - (sum(y - y_pred)^2) / sum(y - mean(y))^2
    # If R^2 = 1, the model is perfect
    # If R^2 = 0, the model is as good as the mean
    # If R^2 < 0, the model is worse than the mean
    def R2score(self, X, y):
        y_pred = self.predict(X)
        return 1 - sum((y - y_pred) ** 2) / sum((y - np.mean(y)) ** 2) # R^2 test to evaluate the model 