class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> week({"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"});
        int day_count = 0;
        for (int y = 1971; y < year; ++y) {
            if (y % 4) {
                day_count += 365;
            }
            else {
                if (y % 100) {
                    day_count += 366;
                }
                else {
                    if (y % 400) {
                        day_count += 365;
                    }
                    else {
                        day_count += 366;
                    }
                }
            }
        }
        
        for (int m = 1; m < month; ++m) {
            if (m == 2) {
                if (year % 4) {
                    day_count += 28;
                }
                else {
                    if (year % 100) {
                        day_count += 29;
                    }
                    else {
                        if (year % 400) {
                            day_count += 28;
                        }
                        else {
                            day_count += 29;
                        }
                    }
                }
            }
            else if (m == 4 || m == 6 || m == 9 || m == 11) {
                day_count += 30;
            }
            else {
                day_count += 31;
            }
        }
        
        day_count += day;
        
        return week[day_count % 7];
    }
};