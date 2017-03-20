# Inna1

Payment_project

I completed the  task assigned for the data engineering competition in Fall 2016.

___________Method______________________________________
So, I used 2D array of size n=max number of users (I made it 1000) and filled it with 0 and 1 (1-if there was past transaction) by opening the batch_payment.txt file and extracting the transactions from there.This matrix is symetric since the connections(graphs) are undirected.
After n*n/2 the table is updated with extra "2" in the cells , corresponding to a second order connection. Inside of these 2 cycles there is extended few more cycles to fill the table with "3" and "4".

I dispay the table after its done just for the visualization (it was more helpful for debugging 5 by 5 table:)).
Then the task of the project if simply to extract Id1 and Id2 from the stream_payment.txt and look at the corresponding x[ID1][ID2] number from the previously described matrix. If its 1- then 1-st order connection, 2- 2nd, etc.
The results are recorded in the output files.
