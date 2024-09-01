# Data Mining LAB : Experiment 4

##  Submitted By:
```
Name: Debatreya Das
Roll No. 12212070
CS A4
Data Mining LAB
```

### Problem Statement
Select a dataset which have issues of missing values and noisy data points. This information can be checked from metadata or documentation provided with the dataset. 
Apply different missing values handing methods  namely  
- Ignore  the  tuple,
- Use  a  global  constant  to  fill  in  the missing value, 
- Use a measure of central tendency for the attribute (e.g., the mean or median) to fill in the missing value, 
- Use the attribute mean or median for all samples belonging to the same class as the given tuple, 
- Use the  most  probable  value  to  fill  in  the  missing  value  on  your  datasets. 
- Further, address  the  issue  of  noisy  data  points  still  pertaining  in  the datasets even after handling the missing values using 
    - Binning and 
    - Regression methods. 
- Analyze the effect of different techniques on dataset in terms of statistical parameters such as central tendency and dispersion.

### Dataset
- [**Heart Disease**](../heart/heart.csv)

### Code and Output
- [**Jupyter Notebook**](./index.ipynb)

### Observations
After applying various techniques for handling missing values and noisy data points, we can observe the following effects on the central tendency and dispersion of the selected attributes (chol for cholesterol and trestbps for resting blood pressure):

1. Ignoring Tuples with Missing Values:
Central Tendency: The mean, median, and mode values are calculated based on the remaining data, potentially leading to biased estimates if the missing data is not randomly distributed.
Dispersion: Ignoring tuples typically reduces the dataset size, which can affect the variance and standard deviation. If the ignored data had extreme values, the range might decrease, and variance and standard deviation might be underestimated.
2. Using a Global Constant:
Central Tendency: Replacing missing values with a constant (e.g., -1) significantly alters the mean, median, and mode, especially if the constant is far from the actual data distribution.
Dispersion: The introduction of a constant leads to a distortion in variance and standard deviation, often inflating these measures since the constant does not reflect the natural variability of the data.
3. Filling with Mean/Median:
Central Tendency: Filling missing values with the mean or median helps maintain the dataset's central tendency. However, it might reduce variability and lead to a slightly biased estimate if the missing data is not random.
Dispersion: The variance and standard deviation might be slightly reduced as filling with the mean or median introduces less variability compared to actual observations.
4. Using Class-Based Mean/Median:
Central Tendency: This approach maintains the central tendency more accurately within specific classes, especially in datasets with distinct subgroups. It reduces the bias introduced by filling with a global mean or median.
Dispersion: Variance and standard deviation are better preserved within each class, maintaining the natural variability of the data.
5. Using the Most Probable Value (Mode):
Central Tendency: Filling missing values with the mode maintains the most frequent value in the dataset, which may lead to a higher peak in the distribution.
Dispersion: This method might reduce the range and variability, especially if the mode is a frequent and non-extreme value, leading to an underestimation of variance and standard deviation.
6. Binning:
Central Tendency: Binning smooths the data by replacing values with the bin’s representative (e.g., bin mean), which can help reduce the impact of noise on central tendency measures.
Dispersion: Binning typically reduces the variance and standard deviation by grouping data into larger intervals, leading to less variation within each bin.
7. Regression:
Central Tendency: Regression replaces noisy values with predicted values based on other attributes, preserving the central tendency while accounting for relationships between variables.
Dispersion: This method reduces noise-induced variability, potentially lowering variance and standard deviation if the original noisy data had outliers.

### Conclusion
From the analysis, we can draw the following conclusions:

- Suitability of Techniques:

    - Ignoring Tuples: Best used when the proportion of missing data is low, as it avoids introducing bias but risks losing valuable information.
    - Global Constant: Should be used cautiously as it can distort the data's central tendency and dispersion, especially if the constant is arbitrary.
    - Filling with Mean/Median: Provides a simple and effective method to handle missing values while preserving central tendency, though it may reduce variability.
    - Class-Based Mean/Median: More accurate for datasets with distinct subgroups, preserving the natural characteristics within each class.
    - Most Probable Value: Effective when the mode is representative, though it may reduce variability.
    - Binning: Useful for reducing the impact of noise, especially when the data has outliers, but may oversimplify the data distribution.
    - Regression: Provides a sophisticated method to smooth noisy data by leveraging relationships between variables, preserving central tendency while reducing noise-induced variability.

- Impact on Statistical Parameters:

    - Techniques that introduce less arbitrary changes (like class-based mean/median and regression) tend to preserve the dataset's natural characteristics better than those that impose constant or mode values.
    - Techniques that smooth the data (like binning and regression) effectively reduce noise but may also reduce the dataset's variability.