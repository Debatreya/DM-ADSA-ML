# Data Mining LAB : Experiment 5

##  Submitted By:
```
Name: Debatreya Das
Roll No. 12212070
CS A4
Data Mining LAB
```

### Problem Statement
Select a dataset which comprises numeric attributes of varying range. Apply different normalization techniques viz. Min-max normalization, z-score normalization, Decimal scaling on your datasets. 
Further, discretize the numeric attributes using Binning and Histogram analysis method. Analyze the effect of different techniques on dataset in terms of type of attributes, statistical parameters such as central tendency and dispersion and change in aptness of proximity metrics

### Data Set
- **WINE**: [Wine Dataset](https://archive.ics.uci.edu/ml/machine-learning-databases/wine-quality/winequality-red.csv)
> For this experiment, I'll use the **Wine Quality** dataset from the [UCI Machine Learning Repository](https://archive.ics.uci.edu/ml/machine-learning-databases/wine-quality/winequality-red.csv). This dataset is ideal because it comprises several numeric attributes with varying ranges, making it suitable for applying different normalization and discretization techniques.

#### **Dataset Overview**

- **Features (Input Variables):**
  - Fixed acidity
  - Volatile acidity
  - Citric acid
  - Residual sugar
  - Chlorides
  - Free sulfur dioxide
  - Total sulfur dioxide
  - Density
  - pH
  - Sulphates
  - Alcohol

- **Target Variable:**
  - Quality (score between 0 and 10)

### Code and Output
- **[Jupyter Notebook](./index.ipynb)**

### Observations
- **Min-Max Normalization**: All attributes are scaled between 0 and 1, making them directly comparable, but it is sensitive to outliers.
- **Z-Score Normalization**: The transformed data has a mean of 0 and unit variance, making it suitable for techniques that assume a normal distribution.
- **Decimal Scaling**: The attributes are scaled by a power of 10. This technique may be more suited for simpler datasets with fewer variations.
- **Discretization**: Both binning techniques reduce the granularity of numeric attributes, but equal-frequency binning captures distributional characteristics better than equal-width binning.
- **Proximity Metrics**: The Euclidean distance changes significantly after normalization. The distances become more meaningful as attributes become comparable in magnitude.

### Conclusion
- **Normalization** techniques significantly impact both the distribution of attributes and their proximity metrics. Min-max normalization makes attributes comparable, whereas Z-score normalization ensures that attributes have a consistent scale but doesn’t retain the original range.
- **Binning** techniques simplify the data by grouping similar values together, but different binning strategies (equal-width vs. equal-frequency) lead to different groupings.
- **Proximity metrics** like Euclidean distance become more meaningful after normalization, as attributes are on a comparable scale.