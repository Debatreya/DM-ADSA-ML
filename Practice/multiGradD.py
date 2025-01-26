import numpy as np

class GD_Regressor:
    def __init__(self, lr=0.01, epochs=1000):
        self.lr = lr
        self.epochs = epochs
        self.coef_ = None
        self.intercept_ = None

    def fit(self, X_train, y_train):
        self.intercept_ = 0
        self.coef_ = np.ones(X_train.shape[1])
        for i in range(self.epochs):
            interceptDer = - 2.0 * np.mean(y_train - self.predict(X_train))
            self.intercept_ = self.intercept_ - (self.lr * interceptDer)

            coefDer = - 2.0 * np.dot(X_train.T, (y_train - self.predict(X_train))) / X_train.shape[0]
            self.coef_ = self.coef_ - (self.lr * coefDer)


    def predict(self, X_test):
        return np.dot(X_test, self.coef_) + self.intercept_
    