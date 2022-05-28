import plotly.express as px
import pandas as pd
import numpy as np

# Load data
df = pd.read_csv('output_example.csv')

# Add a column for the delta (difference between times)
df['delta'] = df['end_time'] - df['start_time']

# Assure string type
df['job'] = df['job'].astype(str)


# Setup Gantt
fig = px.timeline(df, x_start="start_time", x_end="end_time", y="machine", color='job', hover_data=['operation'])

# To show machine's id ascendingly
fig.update_yaxes(autorange="reversed")

# Update the layout -> Allow int values for time, instead of timestamps
fig.layout.xaxis.type = 'linear'

# Fill data to each job, using delta values 
for i in np.arange(len(df['job'].unique())):
    fig.data[i].x = df.delta.tolist()

# Save output as html file and open to view
fig.write_html('first_figure.html', auto_open=True)
