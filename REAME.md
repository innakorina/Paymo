# Inna1

Payment_project

I completed the modified task. I made a mistake using a 2-dimentional array instead of linked lists. As I became very limited in array size, I had to  modify it by cutting number of users to 1000, otherwise my method will not work.
I modified batch_payment.txt and stream_payment.txt by cutting(changing) the large ID numbers into smaller-under 1000.Then the results are stored as the "yes" or  "no" next to the two ID's and are saved in output1.txt for feature 1, output2.txt-for feature 2 and output2.txt- for feature 3.
___________Method______________________________________
So, I used 2D array of size n=max number of users (i made it 1000) and filled it with 0 and 1 (1-if there was past transaction) by opening the batch_payment.txt file and extracting the transactions from there.This matrix is symetric since the connections(graphs) are undirected.
After n*n/2 the table is updated with extra "2" in the cells , corresponding to a second order connection. Inside of these 2 cycles there is extended few more cycles to fill the table with "3" and "4".

I dispay the table after its done just for the visualization (it was more helpful for debugging 5 by 5 table:)).
Then the task of the project if simply to extract Id1 and Id2 from the stream_payment.txt and look at the corresponding x[ID1][ID2] number from the previously described matrix. If its 1- then 1-st order connection, 2- 2nd, etc.
The results are recorded in the output files.
