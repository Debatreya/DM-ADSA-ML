::: {.cell .markdown}
# Statistical Analysis: Iris Dataset

We will calculate the following statistics for each attribute

-   \[\] Central Tendancy
    -   Mean
    -   Median
    -   Mode
-   \[\] Dispersion
    -   Range
    -   Quartiles
    -   InterQuartile Range
    -   Variance
    -   Santard Deviation
-   \[\] Covariance Matrix
-   \[\] Correlation Matrix
:::

::: {.cell .markdown}
## Importing necessary Libraries
:::

::: {.cell .code execution_count="1"}
``` python
import pandas as pd
```
:::

::: {.cell .markdown}
## Load datasets
:::

:::: {.cell .code execution_count="3"}
``` python
iris_df = pd.read_csv('../iris/iris.data', header=None)
iris_df.columns = [
    "sepal_length", "sepal_width", "petal_length", "petal_width", "class" 
]
iris_df
```

::: {.output .execute_result execution_count="3"}
<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>sepal_length</th>
      <th>sepal_width</th>
      <th>petal_length</th>
      <th>petal_width</th>
      <th>class</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>5.1</td>
      <td>3.5</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>Iris-setosa</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4.9</td>
      <td>3.0</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>Iris-setosa</td>
    </tr>
    <tr>
      <th>2</th>
      <td>4.7</td>
      <td>3.2</td>
      <td>1.3</td>
      <td>0.2</td>
      <td>Iris-setosa</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4.6</td>
      <td>3.1</td>
      <td>1.5</td>
      <td>0.2</td>
      <td>Iris-setosa</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5.0</td>
      <td>3.6</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>Iris-setosa</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>145</th>
      <td>6.7</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.3</td>
      <td>Iris-virginica</td>
    </tr>
    <tr>
      <th>146</th>
      <td>6.3</td>
      <td>2.5</td>
      <td>5.0</td>
      <td>1.9</td>
      <td>Iris-virginica</td>
    </tr>
    <tr>
      <th>147</th>
      <td>6.5</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.0</td>
      <td>Iris-virginica</td>
    </tr>
    <tr>
      <th>148</th>
      <td>6.2</td>
      <td>3.4</td>
      <td>5.4</td>
      <td>2.3</td>
      <td>Iris-virginica</td>
    </tr>
    <tr>
      <th>149</th>
      <td>5.9</td>
      <td>3.0</td>
      <td>5.1</td>
      <td>1.8</td>
      <td>Iris-virginica</td>
    </tr>
  </tbody>
</table>
<p>150 rows × 5 columns</p>
</div>
:::
::::

::: {.cell .markdown}
## Handle \'class\' attribute which is a categorial data
:::

:::: {.cell .code execution_count="6"}
``` python
# Handling categorical data

# Iris-setosa -> 0
iris_df.loc[iris_df['class'] == 'Iris-setosa', 'class'] = 0
# Iris-versicolor -> 1
iris_df.loc[iris_df['class'] == 'Iris-versicolor', 'class'] = 1
# Iris-virginica -> 2
iris_df.loc[iris_df['class'] == 'Iris-virginica', 'class'] = 2

iris_df
```

::: {.output .execute_result execution_count="6"}
<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>sepal_length</th>
      <th>sepal_width</th>
      <th>petal_length</th>
      <th>petal_width</th>
      <th>class</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>5.1</td>
      <td>3.5</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4.9</td>
      <td>3.0</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>4.7</td>
      <td>3.2</td>
      <td>1.3</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4.6</td>
      <td>3.1</td>
      <td>1.5</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5.0</td>
      <td>3.6</td>
      <td>1.4</td>
      <td>0.2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>145</th>
      <td>6.7</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.3</td>
      <td>2</td>
    </tr>
    <tr>
      <th>146</th>
      <td>6.3</td>
      <td>2.5</td>
      <td>5.0</td>
      <td>1.9</td>
      <td>2</td>
    </tr>
    <tr>
      <th>147</th>
      <td>6.5</td>
      <td>3.0</td>
      <td>5.2</td>
      <td>2.0</td>
      <td>2</td>
    </tr>
    <tr>
      <th>148</th>
      <td>6.2</td>
      <td>3.4</td>
      <td>5.4</td>
      <td>2.3</td>
      <td>2</td>
    </tr>
    <tr>
      <th>149</th>
      <td>5.9</td>
      <td>3.0</td>
      <td>5.1</td>
      <td>1.8</td>
      <td>2</td>
    </tr>
  </tbody>
</table>
<p>150 rows × 5 columns</p>
</div>
:::
::::

::: {.cell .markdown}
## Compute central tendency (mean, median, mode)
:::

:::: {.cell .code execution_count="7"}
``` python
mean_values = iris_df.mean()
median_values = iris_df.median()
mode_values = iris_df.mode().iloc[0]  # mode() returns a dataframe, so we take the first row

# Combine them into a single DataFrame
central_tendency_table = pd.DataFrame({
    'Mean': mean_values,
    'Median': median_values,
    'Mode': mode_values
})

# Display the table
central_tendency_table
```

::: {.output .execute_result execution_count="7"}
<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>Mean</th>
      <th>Median</th>
      <th>Mode</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>sepal_length</th>
      <td>5.843333</td>
      <td>5.8</td>
      <td>5.0</td>
    </tr>
    <tr>
      <th>sepal_width</th>
      <td>3.054</td>
      <td>3.0</td>
      <td>3.0</td>
    </tr>
    <tr>
      <th>petal_length</th>
      <td>3.758667</td>
      <td>4.35</td>
      <td>1.5</td>
    </tr>
    <tr>
      <th>petal_width</th>
      <td>1.198667</td>
      <td>1.3</td>
      <td>0.2</td>
    </tr>
    <tr>
      <th>class</th>
      <td>1.0</td>
      <td>1.0</td>
      <td>0</td>
    </tr>
  </tbody>
</table>
</div>
:::
::::

::: {.cell .markdown}
## Measures of Dispersion (range, quartiles, InterQuartile Ranges, Variance, Standard Deviations)
:::

:::: {.cell .code execution_count="8"}
``` python
iris_dispersion = iris_df.describe().T
iris_dispersion['IQR'] = iris_dispersion['75%'] - iris_dispersion['25%']
iris_dispersion['Variance'] = iris_dispersion['std'] ** 2

iris_dispersion
```

::: {.output .execute_result execution_count="8"}
<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>count</th>
      <th>mean</th>
      <th>std</th>
      <th>min</th>
      <th>25%</th>
      <th>50%</th>
      <th>75%</th>
      <th>max</th>
      <th>IQR</th>
      <th>Variance</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>sepal_length</th>
      <td>150.0</td>
      <td>5.843333</td>
      <td>0.828066</td>
      <td>4.3</td>
      <td>5.1</td>
      <td>5.80</td>
      <td>6.4</td>
      <td>7.9</td>
      <td>1.3</td>
      <td>0.685694</td>
    </tr>
    <tr>
      <th>sepal_width</th>
      <td>150.0</td>
      <td>3.054000</td>
      <td>0.433594</td>
      <td>2.0</td>
      <td>2.8</td>
      <td>3.00</td>
      <td>3.3</td>
      <td>4.4</td>
      <td>0.5</td>
      <td>0.188004</td>
    </tr>
    <tr>
      <th>petal_length</th>
      <td>150.0</td>
      <td>3.758667</td>
      <td>1.764420</td>
      <td>1.0</td>
      <td>1.6</td>
      <td>4.35</td>
      <td>5.1</td>
      <td>6.9</td>
      <td>3.5</td>
      <td>3.113179</td>
    </tr>
    <tr>
      <th>petal_width</th>
      <td>150.0</td>
      <td>1.198667</td>
      <td>0.763161</td>
      <td>0.1</td>
      <td>0.3</td>
      <td>1.30</td>
      <td>1.8</td>
      <td>2.5</td>
      <td>1.5</td>
      <td>0.582414</td>
    </tr>
  </tbody>
</table>
</div>
:::
::::

::: {.cell .markdown}
# Compute covariance and correlation matrices
:::

::: {.cell .code execution_count="9"}
``` python
iris_covariance = iris_df.cov()
iris_correlation = iris_df.corr()
```
:::

::: {.cell .markdown}
### IRIS Covariance Matrix
:::

:::: {.cell .code execution_count="10"}
``` python
iris_covariance
```

::: {.output .execute_result execution_count="10"}
<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>sepal_length</th>
      <th>sepal_width</th>
      <th>petal_length</th>
      <th>petal_width</th>
      <th>class</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>sepal_length</th>
      <td>0.685694</td>
      <td>-0.039268</td>
      <td>1.273682</td>
      <td>0.516904</td>
      <td>0.530872</td>
    </tr>
    <tr>
      <th>sepal_width</th>
      <td>-0.039268</td>
      <td>0.188004</td>
      <td>-0.321713</td>
      <td>-0.117981</td>
      <td>-0.148993</td>
    </tr>
    <tr>
      <th>petal_length</th>
      <td>1.273682</td>
      <td>-0.321713</td>
      <td>3.113179</td>
      <td>1.296387</td>
      <td>1.371812</td>
    </tr>
    <tr>
      <th>petal_width</th>
      <td>0.516904</td>
      <td>-0.117981</td>
      <td>1.296387</td>
      <td>0.582414</td>
      <td>0.597987</td>
    </tr>
    <tr>
      <th>class</th>
      <td>0.530872</td>
      <td>-0.148993</td>
      <td>1.371812</td>
      <td>0.597987</td>
      <td>0.671141</td>
    </tr>
  </tbody>
</table>
</div>
:::
::::

::: {.cell .markdown}
### IRIS Correlation Matrix
:::

:::: {.cell .code execution_count="11"}
``` python
iris_correlation
```

::: {.output .execute_result execution_count="11"}
<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>sepal_length</th>
      <th>sepal_width</th>
      <th>petal_length</th>
      <th>petal_width</th>
      <th>class</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>sepal_length</th>
      <td>1.000000</td>
      <td>-0.109369</td>
      <td>0.871754</td>
      <td>0.817954</td>
      <td>0.782561</td>
    </tr>
    <tr>
      <th>sepal_width</th>
      <td>-0.109369</td>
      <td>1.000000</td>
      <td>-0.420516</td>
      <td>-0.356544</td>
      <td>-0.419446</td>
    </tr>
    <tr>
      <th>petal_length</th>
      <td>0.871754</td>
      <td>-0.420516</td>
      <td>1.000000</td>
      <td>0.962757</td>
      <td>0.949043</td>
    </tr>
    <tr>
      <th>petal_width</th>
      <td>0.817954</td>
      <td>-0.356544</td>
      <td>0.962757</td>
      <td>1.000000</td>
      <td>0.956464</td>
    </tr>
    <tr>
      <th>class</th>
      <td>0.782561</td>
      <td>-0.419446</td>
      <td>0.949043</td>
      <td>0.956464</td>
      <td>1.000000</td>
    </tr>
  </tbody>
</table>
</div>
:::
::::
