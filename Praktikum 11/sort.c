#include "listrec.h"
#include "sort.h"

void splitList(List source, List* front, List* back) {
   int len = length(source);
   int frontBound = (len % 2) ? (len / 2) : ((len / 2) - 1);

   List p = source;
   int i;
   for (i = 0; i < len; i++) {
      if (i <= frontBound) {
         *front = konsb(*front, INFO(p));
      } else {
         *back = konsb(*back, INFO(p));
      }
      p = NEXT(p);
   }
}

Address findMiddle(List l)  {
   int n = length(l);
   int mid = (n % 2) ? (n / 2) : (n / 2) - 1;

   int i;
   Address p = l;
   for (i = 0; i < mid; i++) {
      p = tail(p);
   }
   return p;
}

List merge(List l1, List l2) {
   List res = NULL;

   if (l1 == NULL) return l2;
   else if (l2 == NULL) return l1;
   else {
      List tempA = l1;
      List tempB = l2;
      ElType val;

      while ((tempA != NULL) && (tempB != NULL)) {
         if (INFO(tempA) <= INFO(tempB)) {
            val = INFO(tempA);
            tempA = tail(tempA);
         } else {
            val = INFO(tempB);
            tempB = tail(tempB);
         } 
         res = konsb(res, val);
      }

      while (tempA != NULL) {
         val = INFO(tempA);
         tempA = tail(tempA);
         res = konsb(res, val);
      }

      while (tempB != NULL) {
         val = INFO(tempB);
         tempB = tail(tempB);
         res = konsb(res, val);
      }

      return res;
   }
}

List mergeSort(List l) {
   if (length(l) <= 1) return l;
   
   List front = NULL;
   List back = NULL;

   splitList(l, &front, &back);
   front = mergeSort(front);
   back = mergeSort(back);

   return merge(front, back);
}

List getInit(List l, ElType* last) {
   Address p = l;
   List res = NULL;
   
   while (p != NULL) {
      if (NEXT(p) == NULL) {
         *last = INFO(p);
      } else {
         res = konsb(res, INFO(p));
      }
      p = NEXT(p);
   }

   return res;
}

List zigZagSort(List l) {
   List copy = mergeSort(l);
   
   List res = NULL;
   ElType last;

   int i = 1;
   while (!isEmpty(copy)) {
      if (i % 2) {
         res = konsb(res, head(copy));
         copy = tail(copy);
      } else {
         copy = getInit(copy, &last);
         res = konsb(res, last);
      }
      i += 1;
   }
   return res;
}