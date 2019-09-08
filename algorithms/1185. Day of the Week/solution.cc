class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // Zeller's congruence: https://en.wikipedia.org/wiki/Zeller%27s_congruence
        vector<string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if (month < 3) {
            --year;
            month += 12;
        }
        int k = year % 100;
        int j = year / 100;
        int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
        return weekdays[(h + 6) % 7];
    }
};
