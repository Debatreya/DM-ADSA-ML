import numpy as np
import numpy as np
from collections import defaultdict

class NaiveBayesClassifier:
    def __init__(self):
        self.classes = None
        self.mean = {}
        self.var = {}
        self.priors = {}
    
    def fit(self, X, y):
        self.classes = np.unique(y)
        for cls in self.classes:
            X_cls = X[y == cls]
            self.mean[cls] = np.mean(X_cls, axis=0)
            self.var[cls] = np.var(X_cls, axis=0)
            self.priors[cls] = X_cls.shape[0] / X.shape[0]
    
    def _calculate_likelihood(self, mean, var, x):
        exponent = np.exp(-((x - mean) ** 2) / (2 * var))
        return exponent / np.sqrt(2 * np.pi * var)
    
    def _calculate_posterior(self, x):
        posteriors = {}
        for cls in self.classes:
            prior = np.log(self.priors[cls])
            likelihood = np.sum(np.log(self._calculate_likelihood(self.mean[cls], self.var[cls], x)))
            posteriors[cls] = prior + likelihood
        return posteriors
    
    def predict(self, X):
        y_pred = [max(self._calculate_posterior(x), key=self._calculate_posterior(x).get) for x in X]
        return np.array(y_pred)

# Example usage:
if __name__ == "__main__":
    # Sample dataset (X: features, y: labels)
    X = np.array([[1, 20], [2, 21], [3, 22], [4, 19], [5, 18], [6, 17], [7, 16], [8, 15], [9, 14], [10, 13]])
    y = np.array([0, 0, 0, 0, 1, 1, 1, 1, 1, 1])

    # Create a Naive Bayes classifier and train it
    nb_classifier = NaiveBayesClassifier()
    nb_classifier.fit(X, y)

    # Predict on new data
    X_new = np.array([[3, 21], [7, 15]])
    y_pred = nb_classifier.predict(X_new)
    
    print("Predicted labels:", y_pred)