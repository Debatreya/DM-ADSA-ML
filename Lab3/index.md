# Data Mining LAB : Experiment 3

##  Submitted By:
```
Name: Debatreya Das
Roll No. 12212070
CS A4
Data Mining LAB
```

### Problem Statement
>Select two publically available datasets comprising different types 
of attributes viz. nominal, ordinal, interval-scaled and ratio-scaled. __A 
dataset must comprise minimally 2 different types of attribute.__ <br>
>Compute the 
- `proximity (similarity and/or dissimilarity) between data points using 
following metrics`: 
   - Simple Matching Coefficient, 
   - Jaccard Coefficient, 
   - Cosine Similarity, 
   - Euclidean Distance, 
   - Manhattan Distance, 
   - Supremum Distance, and 
   - Correlation as similarity metric. 

>Initially consider each attribute individually for populating corresponding proximity matrix then consider each data object as represented by a vector of mixed attribute types and compute the proximity matrix for your dataset. 
>> Discuss your observation regarding applicability of different metric and any pattern prevailing in your data. 

### Datasets used
- **ADULT**: [Adult Dataset](../adult/adult.data)
- **TITANIC**: [Titanic Dataset](../titanic/train.csv)

### Code and Output
- **Jupyter Notebooks**
   - [Simple Matching Coefficient](./SimpleMatching.ipynb)
   - [Jaccard Coefficient](./Jaccard.ipynb)
   - [Cosine Similarity](./CosineSimilarity.ipynb)
   - [Euclidean Distance](./EuclideanDist.ipynb) 
   - [Manhattan Distance](./ManhattanDist.ipynb)
   - [Supremum Distance](./SupremumDist.ipynb)
   - [Correlation as similarity metric](./Correleation.ipynb)

### Observation and Discussion
After computing the proximity metrics:

`Simple Matching` & `Jaccard Coefficients` are particularly useful for nominal attributes. SMC includes all matches, while Jaccard focuses only on the presence/absence match.

`Euclidean & Manhattan Distances` are more sensitive to differences in scale, which is why standardization might be necessary before applying them to attributes with different scales.

`Cosine Similarity` is useful when the magnitude of the data points is irrelevant, focusing purely on the direction of the data points.

`Supremum Distance` is useful when interested in the maximum difference among dimensions, often highlighting outliers.

`Correlation` is apt for understanding linear relationships between attributes, especially in interval or ratio-scaled data.

### Conclusion
Each proximity metric has its own strengths and is applicable in different contexts based on the type of attributes and the specific analysis goal. Mixed-type datasets, like those in the experiment, require careful selection of proximity metrics to ensure meaningful comparisons.