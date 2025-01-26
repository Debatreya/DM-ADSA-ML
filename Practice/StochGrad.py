import numpy as np

class SGD_Regressor:
    # Stochastic Gradient Descent Regressor
    def __init__(self, lr=0.01, epochs=1000):
        self.lr = lr
        self.epochs = epochs
        self.coef_ = None
        self.intercept_ = None

    def fit(self, X_train, y_train):
        self.intercept_ = 0
        self.coef_ = np.ones(X_train.shape[1])
        for i in range(self.epochs):
            # interceptDer = - 2.0 * np.mean(y_train - self.predict(X_train))
            # self.intercept_ = self.intercept_ - (self.lr * interceptDer)

            # coefDer = - 2.0 * np.dot(X_train.T, (y_train - self.predict(X_train))) / X_train.shape[0]
            # self.coef_ = self.coef_ - (self.lr * coefDer)
            for j in range(X_train.shape[0]):
                idx = np.random.randint(X_train.shape[0])

                y_pred = np.dot(X_train[idx], self.coef_) + self.intercept_

                interceptDer = - 2.0 * (y_train[idx] - y_pred)
                self.intercept_ = self.intercept_ - (self.lr * interceptDer)

                coefDer = - 2.0 * X_train[idx] * (y_train[idx] - y_pred)
                self.coef_ = self.coef_ - (self.lr * coefDer)

        return self.coef_, self.intercept_


    def predict(self, X_test):
        return np.dot(X_test, self.coef_) + self.intercept_
    