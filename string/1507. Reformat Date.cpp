class Solution {
public:
    string reformatDate(string date) {
        string day, month, year, d, ans;
        stringstream ss(date);
        ss >> day >> month >> year;
        for(int i = 0; i < day.size(); i++)
        {
            if(day[i] >=48 && day[i] <= 57)
            {
                d += day[i];
            }
        }
        if(d.size()<2)
            d = "0" + d;
        unordered_map<string, string> um{{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"},                 {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

        return year + "-" + um[month] + "-" + d;
    }
};
