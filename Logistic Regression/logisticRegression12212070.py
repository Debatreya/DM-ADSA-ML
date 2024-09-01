#!/usr/bin/env python
# coding: utf-8

# # Logistic Regression
# > Debatreya Das </br>
# > Roll No. 12212070 </br>
# > ML Lab CS A4 (20th Aug) </br>

# ### Importing the required libraries

# In[1]:


import pandas as pd 
import numpy as np 


# ### Loading the data frames

# In[2]:


df = pd.read_csv('./bank/bank.csv', sep=';')
df


# ### One-Hot Encoding (of categorical data)
# One-Hot Encoding is a method of representing characters or words by a vector where only one element is set to one and all others are zero, based on their position in the vocabulary. This results in a sparse, semantically independent vector with a high dimension.

# In[3]:


data = pd.get_dummies(df, drop_first=True)
data


# ### Separate Dependent Varables (Y) and Independent Variables (X)

# In[4]:


X = data.iloc[:, :-1].values  # 'y_yes' is the encoded target column after one-hot encoding
Y = data.iloc[:, -1].values
X = np.array(X,dtype=int)
print(X)
print(Y)


# ### Normalize / Standardise features (calculatind z-score of normal distribution)
# $$z= (X−μ) / σ$$
# 

# In[5]:


X_mean = np.mean(X, axis=0)
X_std = np.std(X, axis=0)

X_std[X_std == 0] = 1

x = (X - X_mean) / X_std

x


# ### Logistc Regression Model

# In[21]:


class LogisticRegressionManual:
    def __init__(self, learning_rate=0.001, iterations=1000):
        self.learning_rate = learning_rate
        self.iterations = iterations
    
    def sigmoid(self, z):
        z = np.clip(z, -500, 500)  # Clip to avoid overflow
        return 1 / (1 + np.exp(-z))
    
    def fit(self, X, y):
        self.m, self.n = X.shape
        self.W = np.zeros(self.n)
        self.b = 0
        self.X = X
        self.y = y
        
        for i in range(self.iterations):
            # Linear model
            z = np.dot(self.X, self.W) + self.b
            # Sigmoid function
            y_pred = self.sigmoid(z)
            
            # Gradient descent
            dW = (1/self.m) * np.dot(self.X.T, (y_pred - self.y))
            db = (1/self.m) * np.sum(y_pred - self.y)
            
            # Update weights
            self.W -= self.learning_rate * dW
            self.b -= self.learning_rate * db
            
    
    def predict(self, X):
        z = np.dot(X, self.W) + self.b
        y_pred = self.sigmoid(z)
        y_pred_class = [1 if i > 0.5 else 0 for i in y_pred]
        return y_pred_class


# ### Splitting the Dataset and Training Model

# In[23]:


split_ratio = 0.7
split_index = int(split_ratio * len(X))

X_train, X_test = X[:split_index], X[split_index:]
y_train, y_test = Y[:split_index], Y[split_index:]

model = LogisticRegressionManual(learning_rate=0.001, iterations=1000)
model.fit(X_train, y_train)


# ### Make Predictions

# In[24]:


y_pred = model.predict(X_test)


# ### Printing some predictions

# In[25]:


print("\nPredicted vs Actual:")
print("Predicted:", y_pred[:10])
print("Actual:   ", y_test[:10])


# ### Check accuracy (Evaluate Model)

# In[26]:


accuracy = np.sum(y_pred == y_test) / len(y_test)
print(f"\nModel accuracy: {accuracy * 100:.2f}%")

