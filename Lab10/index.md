# Lab 10
## Experimets on Data Warehouse

a) Create A data warehouse from different .csv files using PostgreSQL tool
    [Experiment Part A](./Part%20A/index.ipynb)

b) Using Postgres, create a data warehouse for the following star schema. (The schema and sample data are given in the LAB Manual.)
Write the following queries:
1. Find the total sales.
2. Find total sales for each city.
3. Find total sales for each state.
4. Find total sales for each country.
5. Find sales of all cities of a specific state in a specific year.
6. Find year-wise total sales for each state.
7. Find year-wise total sales for each country.

PostgreSQL supports OLAP operations by extending GROUP BY as GROUP BY CUBE.
Write the above SQLs in using OLAP operations. (drill-down, roll-up).
    [Experiment Part B](./Part%20A/index.ipynb)