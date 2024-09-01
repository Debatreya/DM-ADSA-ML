import numpy as np
import pandas as pd

# Loading Data from a CSV File
data = pd.read_csv('./a1.csv')
print(data)

# Separating concept features from Target
concepts = np.array(data.iloc[:, 0:-1])
print(concepts)
# Isolating target into a separate DataFrame
# Copying last column to target array
target = np.array(data.iloc[:, -1])
print(target)


def mea(concepts, target):
    # Initialise S0 with the first instance from concepts
    specific_h = concepts[0].copy()
    print("\nInitialization of specific_h and general_h")
    print(specific_h)
    
    general_h = [["?" for i in range(len(specific_h))] for i in range(len(specific_h))]
    print(general_h)
    
    # The learning iterations
    for i, h in enumerate(concepts):
        # Checking if the hypothesis has a positive target
        if target[i] == "yes":
            for x in range(len(specific_h)):
                # Change values in S & G only if values change
                if h[x] != specific_h[x]:
                    specific_h[x] = '?'
                    general_h[x][x] = '?'
        # Checking if the hypothesis has a negative target
        if target[i] == "no":
            for x in range(len(specific_h)):
                # For negative hypothesis change values only in G
                if h[x] != specific_h[x]:
                    general_h[x][x] = specific_h[x]
                else:
                    general_h[x][x] = '?'
                    print("\nSteps of Candidate Elimination Algorithm", i+1)
        print(specific_h)
        print(general_h)
    
    # Find indices where we have empty rows, meaning those that are unchanged
    indices = [i for i, val in enumerate(general_h) if val == ['?', '?', '?', '?', '?', '?']]
    for i in indices:
        # Remove those rows from general_h
        general_h.remove(['?', '?', '?', '?', '?', '?'])
    
    # Return final values
    return specific_h, general_h
s_final, g_final = mea(concepts, target)
print("\nFinal Specific_h:", s_final, sep="\n")
print("\nFinal General_h:", g_final, sep="\n")