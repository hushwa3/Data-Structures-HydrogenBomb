#include <stdio.h>

int main() {
    int scores[7], lowestScore, highestScore, i, sum, avg;

    // Read the scores.
    for (i = 0; i < 7; i++) {
    printf("Input score #%d: ", i + 1);
    scanf("%d", &scores[i]);
  }

    // Find the highest and lowest scores.
    lowestScore = scores[0];
    highestScore = scores[0];
    for (i = 1; i < 7; i++) {
      if (scores[i] > highestScore) {
      highestScore = scores[i];
      } else if (scores[i] < lowestScore) {
      lowestScore = scores[i];
    }
  }

      // Calculate the average score, excluding the highest and lowest scores.
    sum = 0;
    for (i = 1; i < 6; i++) {
    sum += scores[i];
  }
    avg = sum / 5;

    // Print the average score.
    printf("Average Score: %d\n", avg);

    return 0;
}

