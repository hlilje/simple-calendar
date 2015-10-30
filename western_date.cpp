#include "western_date.hpp"


int lab2::WesternDate::year() {
    return _year;
}

unsigned int lab2::WesternDate::month() {
    return _month;
}

unsigned int lab2::WesternDate::day() {
    return _day;
}

unsigned int lab2::WesternDate::week_day() {
    return ((_offset + 3) % 7) + 1;
}

unsigned int lab2::WesternDate::days_per_week() {
    return 7;
}

std::string lab2::WesternDate::week_day_name() {
    switch (week_day()) {
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        case 7:
            return "Sunday";
        default:
            return "";
    }
}

std::string lab2::WesternDate::month_name() {
    switch (_month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "";
    }
}
