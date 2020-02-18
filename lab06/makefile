compRecMS:	mergeSortRec.c merge.c main.c
	gcc main.c merge.c mergeSortRec.c -o mergeSortRec.out

compItrMS:	mergeSortItr.c merge.c main.c
	gcc main.c merge.c mergeSortItr.c -o mergeSortItr.out

runRecMS:	mergeSortRec.out
	./mergeSortRec.out 1024.txt

runItrMS:	mergeSortItr.out
	./mergeSortItr.out 1024.txt

compare:	mergeSortRec.out mergeSortItr.out
	./mergeSortItr.out && ./mergeSortRec.out