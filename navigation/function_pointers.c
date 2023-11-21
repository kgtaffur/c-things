#include <stdio.h>
#include <string.h>

#include <stdlib.h>

int NUM_ADS = 7;
char *ADS[] = {
    "William: SBM GSOH likes sports, TV, dining",
    "Matt: SWM NS likes art, movies, theater",
    "Luis: SLM ND likes books, theater, art",
    "Mike: DWM DS likes trucks, sports and bieber",
    "Peter: SAM likes chess, working out and art",
    "Josh: SJM likes sports, movies and theater",
    "Jed: DBM likes theater, books and dining",
};

int sports_no_bieber(char *s) {
  return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_workout(char *s) {
  return strstr(s, "sports") || strstr(s, "working out");
}

int ns_theater(char *s) { return strstr(s, "NS") && strstr(s, "theater"); }

int arts_theater_or_dining(char *s) {
  return strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining");
}

void find(int (*match)(char *)) {
  int i;
  puts("Search results:");
  puts("=============================");
  for (i = 0; i < NUM_ADS; i++) {
    if (match(ADS[i])) {
      printf("%s\n", ADS[i]);
    }
  }
  puts("==============================");
}

// FIRST GREATER THAN SECOND -> POSITIVE
// FIRST LESS THAN SECOND -> NEGATIVE
// EQUALS -> 0

// sort integer scores, with the smallest first
int compare_scores(const void *score_a, const void *score_b) {
  int a = *(int *)score_a;
  int b = *(int *)score_b;

  return a - b;
}

// sort integer scores, with the largest first
int compare_scores_desc(const void *score_a, const void *score_b) {
  int a = *(int *)score_a;
  int b = *(int *)score_b;

  return b - a;
}

// sort the rectangles in area order, smallest first
typedef struct {
  int width;
  int height;
} rectangle;

int compare_areas(const void *a, const void *b) {
  int area1 = ((rectangle *)a)->width * ((rectangle *)a)->height;
  int area2 = ((rectangle *)b)->width * ((rectangle *)b)->height;

  return area1 - area2;
}

// sort a list of names in alphabetical order, case-sensitive
int compare_names(const void *a, const void *b) {
  char **str_a = (char **)a;
  char **str_b = (char **)b;

  return strcmp(*str_a, *str_b);
}

// sort the rectangles in area order, largest first
int compare_areas_desc(const void *a, const void *b) {
  return -compare_areas(a, b);
}

// sort a list of names in reverse alphabetical order. case-sensitive
int compare_names_desc(const void *a, const void *b) {
  return -compare_names(a, b);
}

int main() {
  // find(sports_no_bieber);
  // find(sports_or_workout);
  // find(ns_theater);
  // find(arts_theater_or_dining);

  int scores[] = {543, 323, 32, 554, 11, 3, 112};
  int i;

  // arr, array size, item size, fn to compare
  qsort(scores, 7, sizeof(int), compare_scores_desc);
  puts("These are the scores in desc order:");

  for (i = 0; i < 7; i++) {
    printf("Score = %i\n", scores[i]);
  }

  char *names[] = {"Karen", "Mar", "Brett", "Molly"};

  qsort(names, 4, sizeof(char *), compare_names);
  puts("These are the names in order:");

  for (i = 0; i < 4; i++) {
    printf("%s\n", names[i]);
  }

  return 0;
}
