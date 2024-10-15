#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

// Function to calculate the difference between two times
Time time_difference(Time t1, Time t2) {
    Time diff;
    
    // Convert both times to seconds for easier computation
    int total_seconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int total_seconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the difference in seconds
    int difference_in_seconds = total_seconds1 - total_seconds2;

    // If the difference is negative, adjust for wrapping
    if (difference_in_seconds < 0) {
        difference_in_seconds += 24 * 3600; // Wrap around a day
    }

    // Calculate hours, minutes, and seconds from the difference
    diff.hours = difference_in_seconds / 3600;
    difference_in_seconds %= 3600;
    diff.minutes = difference_in_seconds / 60;
    diff.seconds = difference_in_seconds % 60;

    return diff;
}

// Function to add seconds to a given time
Time add_seconds(Time t, int seconds_to_add) {
    int total_seconds = t.hours * 3600 + t.minutes * 60 + t.seconds + seconds_to_add;
    
    // Calculate the new time and wrap around if necessary
    total_seconds = total_seconds % (24 * 3600); // Keep it within a day

    Time new_time;
    new_time.hours = total_seconds / 3600;
    total_seconds %= 3600;
    new_time.minutes = total_seconds / 60;
    new_time.seconds = total_seconds % 60;

    return new_time;
}

int main() {
    Time time1, time2;
    int seconds_to_add;

    // Input first time
    printf("Enter first time (HH MM SS): ");
    scanf("%d %d %d", &time1.hours, &time1.minutes, &time1.seconds);
    
    // Input second time
    printf("Enter second time (HH MM SS): ");
    scanf("%d %d %d", &time2.hours, &time2.minutes, &time2.seconds);
    
    // Calculate and display the difference
    Time diff = time_difference(time1, time2);
    printf("Time Difference: %02d:%02d:%02d\n", diff.hours, diff.minutes, diff.seconds);

    // Input seconds to add
    printf("Enter seconds to add to the first time: ");
    scanf("%d", &seconds_to_add);
    
    // Calculate and display new time
    Time new_time = add_seconds(time1, seconds_to_add);
    printf("New Time after adding seconds: %02d:%02d:%02d\n", new_time.hours, new_time.minutes, new_time.seconds);

    return 0;
}
