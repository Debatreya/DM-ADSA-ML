# Find-S Algorithm : It is a concept learning algorithm that generates a maximally specific hypothesis from the given training examples.
# The hypothesis space is the space of all hypotheses defined by the representation language.
# The hypothesis is represented by a conjunction of literals.
# The algorithm is as follows:
# 1. Initialize h to the most specific hypothesis in H
# 2. For each positive training instance x
#    For each attribute constraint a i in h
#       If the constraint a i in h is satisfied by x
#          Then do nothing
#       Else
#          Replace a i in h by the next more general constraint that is satisfied by x
# 3. Output hypothesis h

# Importing the required libraries
import pandas as pd

# Load the dataset
data = pd.read_csv('./a.csv')
# set of possible values for each attribute
attribute_values = [set(data[i]) for i in data.columns[:-1]]  # Exclude the last column 'poisonous'

def FindS(Data):
    # Initialize the specific hypothesis as list of 4 set elements
    h = [set() for i in range(4)]

    # For each positive training instance x
    for index, row in Data.iterrows():
        if row['poisonous'] == 'yes':
            # For each attribute constraint a i in h
            # I will always add in case of 'yes' as I am using a set (set stores unique elements only)
            for i, attr in enumerate(row[:-1]):  # Exclude the last column 'poisonous'
                h[i].add(attr)

    # If all attributes are present in the hypothesis, then replace it with '?'
    for i in range(4):
        if len(h[i]) == len(attribute_values[i]):
            h[i] = '?'  # Replace with '?'
    return h


# ##### Test the FindS algorithm

# Find the maximally specific hypothesis
h = FindS(data)

# Print the maximally specific hypothesis
print("The maximally specific hypothesis is:", h)

# Test the hypothesis with a new test data
testData = pd.read_csv('./test.csv')

def test(h, testData):
    for index, row in testData.iterrows():
        flag = 1
        for i, attr in enumerate(row[:-1]):
            if h[i] != '?' and attr not in h[i]:
                flag = 0
                break
        if flag == 1:
            print("The test instance", row.tolist(), "yes")
        else:
            print("The test instance", row.tolist(), "no")

# Test the hypothesis
test(h, testData)
