#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;

#include "Date.h"
#include "Utils.h"

using namespace sdds;

namespace sdds {

    bool sdds_test = false;
    int sdds_year = 2022;
    int sdds_mon = 8;
    int sdds_day = 7;

    bool Date::validate() {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }
    int Date::mdays()const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }
    int Date::systemYear()const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }
    void Date::setToToday() {
        if (sdds_test) {
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(NO_ERROR);
    }
    int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }
    Date::Date() :m_CUR_YEAR(systemYear()) {
        setToToday();
    }
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }
    const char* Date::dateStatus()const {
        return DATE_ERROR[errCode()];
    }
    int Date::currentYear()const {
        return m_CUR_YEAR;
    }
    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }
    int Date::errCode()const {
        return m_ErrorCode;
    }
    bool Date::bad()const {
        return m_ErrorCode != 0;
    }

    ostream& operator<<(ostream& os, const Date& RO) {
        return RO.write(os);
    }

    istream& operator>>(istream& is, Date& RO) {
        return RO.read(is);
    }

    // This function reads a date from the console
    istream& Date::read(istream& is) {
        m_ErrorCode = NO_ERROR;
        is >> m_year;
        is.ignore();
        is >> m_mon;
        is.ignore();
        is >> m_day;
        if (is.fail()) {            // checks if cin is in a failed state
            m_ErrorCode = CIN_FAILED;
            is.clear();            // clears state to allow further extraction 
        }
        else
        {
            if (m_year < 1500 || m_year > 2022)
            {
                m_ErrorCode = YEAR_ERROR;
            }
            else if (m_mon < 1 || m_mon > 12)
            {
                m_ErrorCode = MON_ERROR;
            }
            else
            {
                switch (m_mon)
                {
                case 1:
                    if (m_day > 31 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 2:
                    if (m_year % 4 != 0)
                    {
                        if (m_day > 28 || m_day < 1)
                        {
                            m_ErrorCode = DAY_ERROR;
                        }
                    }
                    else
                    {
                        if (m_day > 29 || m_day < 1)
                        {
                            m_ErrorCode = DAY_ERROR;
                        }
                    }
                    break;
                case 3:
                    if (m_day > 31 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 4:
                    if (m_day > 30 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 5:
                    if (m_day > 31 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 6:
                    if (m_day > 30 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 7:
                    if (m_day > 31 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 8:
                    if (m_day > 31 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 9:
                    if (m_day > 30 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 10:
                    if (m_day > 31 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 11:
                    if (m_day > 30 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                case 12:
                    if (m_day > 31 || m_day < 1)
                    {
                        m_ErrorCode = DAY_ERROR;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        return is;
    }

    // If the date is invalid it will print the date
    ostream& Date::write(ostream& os)const {
        if (bad())
        {
            os << dateStatus();
        }
        else
        {
            os << m_year << '/';
            os.setf(ios::fixed);
            os.width(2);
            os.fill('0');
            os << m_mon << '/';
            os.unsetf(ios::fixed);
            os.setf(ios::fixed);
            os.width(2);
            os.fill('0');
            os << m_day;
            os.unsetf(ios::fixed);
        }
        return os;
    }

    // checks if the date value are equal
    bool Date::operator==(const Date& date)const {
        return daysSince0001_1_1() == date.daysSince0001_1_1();
    }

    // checks if the date value are not equal
    bool Date::operator!=(const Date& date)const {
        return daysSince0001_1_1() != date.daysSince0001_1_1();
    }

    // checks if the date values are greater than and equal
    bool Date::operator>=(const Date& date)const {
        return daysSince0001_1_1() >= date.daysSince0001_1_1();
    }

    // checks if the date value are less than and equal
    bool Date::operator<=(const Date& date)const {
        return daysSince0001_1_1() <= date.daysSince0001_1_1();
    }

    // checks if the date value are less than
    bool Date::operator<(const Date& date)const {
        return daysSince0001_1_1() < date.daysSince0001_1_1();
    }

    // checks if the date value are greater than
    bool Date::operator>(const Date& date)const {
        return daysSince0001_1_1() > date.daysSince0001_1_1();
    }

    // Returns the difference between two Dates in days.
    int Date::operator-(const Date& date)const {
        int days = 0;
        if (m_year == date.m_year)
        {
            if (m_mon == date.m_mon)
            {
                days += m_day - date.m_day;
                return days;
            }
            else if (m_mon > date.m_mon)
            {
                if (m_mon - date.m_mon > 1)
                {
                    for (int i = 0; i < m_mon - date.m_mon - 1; i++)
                    {
                        switch (date.m_mon + 1 + i)
                        {
                        case 2:
                            if (date.m_year % 4 == 0)
                            {
                                days += 29;
                            }
                            days += 28;
                            break;
                        case 3:
                            days += 31;
                            break;
                        case 4:
                            days += 30;
                            break;
                        case 5:
                            days += 31;
                            break;
                        case 6:
                            days += 30;
                            break;
                        case 7:
                            days += 31;
                            break;
                        case 8:
                            days += 31;
                            break;
                        case 9:
                            days += 30;
                            break;
                        case 10:
                            days += 31;
                            break;
                        case 11:
                            days += 30;
                            break;
                        default:
                            break;
                        }
                    }
                    days += m_day;
                    switch (date.m_mon)
                    {
                    case 1:
                        days += 31 - date.m_day;
                        break;
                    case 2:
                        days += 30 - date.m_day;
                        break;
                    case 3:
                        days += 31 - date.m_day;
                        break;
                    case 4:
                        days += 30 - date.m_day;
                        break;
                    case 5:
                        days += 31 - date.m_day;
                        break;
                    case 6:
                        days += 30 - date.m_day;
                        break;
                    case 7:
                        days += 31 - date.m_day;
                        break;
                    case 8:
                        days += 31 - date.m_day;
                        break;
                    case 9:
                        days += 30 - date.m_day;
                        break;
                    case 10:
                        days += 31 - date.m_day;
                        break;
                    case 11:
                        days += 30 - date.m_day;
                        break;
                    case 12:
                        days += 31 - date.m_day;
                        break;
                    default:
                        break;
                    }
                    return days;
                }
                else
                {
                    days += m_day;
                    switch (date.m_mon)
                    {
                    case 1:
                        days += 31 - date.m_day;
                        break;
                    case 2:
                        days += 30 - date.m_day;
                        break;
                    case 3:
                        days += 31 - date.m_day;
                        break;
                    case 4:
                        days += 30 - date.m_day;
                        break;
                    case 5:
                        days += 31 - date.m_day;
                        break;
                    case 6:
                        days += 30 - date.m_day;
                        break;
                    case 7:
                        days += 31 - date.m_day;
                        break;
                    case 8:
                        days += 31 - date.m_day;
                        break;
                    case 9:
                        days += 30 - date.m_day;
                        break;
                    case 10:
                        days += 31 - date.m_day;
                        break;
                    case 11:
                        days += 30 - date.m_day;
                        break;
                    case 12:
                        days += 31 - date.m_day;
                        break;
                    default:
                        break;
                    }
                    return days;
                }
            }
            else if (m_mon < date.m_mon)
            {
                if (date.m_mon - m_mon > 1)
                {
                    for (int i = 0; i < date.m_mon - m_mon - 1; i++)
                    {
                        switch (date.m_mon + 1 + i)
                        {
                        case 2:
                            if (date.m_year % 4 == 0)
                            {
                                days += 29;
                            }
                            days += 28;
                            break;
                        case 3:
                            days += 31;
                            break;
                        case 4:
                            days += 30;
                            break;
                        case 5:
                            days += 31;
                            break;
                        case 6:
                            days += 30;
                            break;
                        case 7:
                            days += 31;
                            break;
                        case 8:
                            days += 31;
                            break;
                        case 9:
                            days += 30;
                            break;
                        case 10:
                            days += 31;
                            break;
                        case 11:
                            days += 30;
                            break;
                        default:
                            break;
                        }
                    }
                }
                days += date.m_day;
                switch (m_mon)
                {
                case 1:
                    days += 31 - m_day;
                    break;
                case 2:
                    days += 30 - m_day;
                    break;
                case 3:
                    days += 31 - m_day;
                    break;
                case 4:
                    days += 30 - m_day;
                    break;
                case 5:
                    days += 31 - m_day;
                    break;
                case 6:
                    days += 30 - m_day;
                    break;
                case 7:
                    days += 31 - m_day;
                    break;
                case 8:
                    days += 31 - m_day;
                    break;
                case 9:
                    days += 30 - m_day;
                    break;
                case 10:
                    days += 31 - m_day;
                    break;
                case 11:
                    days += 30 - m_day;
                    break;
                case 12:
                    days += 31 - m_day;
                    break;
                default:
                    break;
                }
                return -(days);
            }
        }
        else if (m_year > date.m_year)
        {
            if (m_year - date.m_year > 1)
            {
                for (int i = 0; i < m_year - date.m_year - 1; i++)
                {
                    if ((m_year + i) % 4 == 0)
                    {
                        days += 366;
                    }
                    else
                    {
                        days += 365;
                    }
                }
            }
            if (date.m_mon > 2 && date.m_year % 4 == 0)
            {
                days++;
            }
            switch (date.m_mon)
            {
            case 1:
                days += date.m_day;
                break;
            case 2:
                days += 31 + date.m_day;
                break;
            case 3:
                days += 59 + date.m_day;
                break;
            case 4:
                days += 90 + date.m_day;
                break;
            case 5:
                days += 120 + date.m_day;
                break;
            case 6:
                days += 151 + date.m_day;
                break;
            case 7:
                days += 181 + date.m_day;
                break;
            case 8:
                days += 212 + date.m_day;
                break;
            case 9:
                days += 243 + date.m_day;
                break;
            case 10:
                days += 273 + date.m_day;
                break;
            case 11:
                days += 304 + date.m_day;
                break;
            case 12:
                days += 334 + date.m_day;
                break;
            default:
                break;
            }
            if (m_year % 4 == 0 && m_mon < 3)
            {
                days++;
            }
            switch (m_mon)
            {
            case 1:
                days += 334 + 31 - m_day;
                break;
            case 2:
                days += 306 + 28 - m_day;
                break;
            case 3:
                days += 275 + 31 - m_day;
                break;
            case 4:
                days += 245 + 30 - m_day;
                break;
            case 5:
                days += 214 + 31 - m_day;
                break;
            case 6:
                days += 184 + 30 - m_day;
                break;
            case 7:
                days += 153 + 31 - m_day;
                break;
            case 8:
                days += 122 + 31 - m_day;
                break;
            case 9:
                days += 92 + 30 - m_day;
                break;
            case 10:
                days += 61 + 31 - m_day;
                break;
            case 11:
                days += 31 + 30 - m_day;
                break;
            case 12:
                days += 31 - m_day;
                break;
            default:
                break;
            }
            return days;
        }
        else if (m_year < date.m_year)
        {
            if (date.m_year - m_year > 1)
            {
                for (int i = 0; i < date.m_year - m_year - 1; i++)
                {
                    if ((date.m_year + i) % 4 == 0)
                    {
                        days += 366;
                    }
                    else
                    {
                        days += 365;
                    }
                }
            }
            if (m_mon > 2 && m_year % 4 == 0)
            {
                days++;
            }
            switch (m_mon)
            {
            case 1:
                days += m_day;
                break;
            case 2:
                days += 31 + m_day;
                break;
            case 3:
                days += 59 + m_day;
                break;
            case 4:
                days += 90 + m_day;
                break;
            case 5:
                days += 120 + m_day;
                break;
            case 6:
                days += 151 + m_day;
                break;
            case 7:
                days += 181 + m_day;
                break;
            case 8:
                days += 212 + m_day;
                break;
            case 9:
                days += 243 + m_day;
                break;
            case 10:
                days += 273 + m_day;
                break;
            case 11:
                days += 304 + m_day;
                break;
            case 12:
                days += 334 + m_day;
                break;
            default:
                break;
            }
            if (date.m_year % 4 == 0 && date.m_mon < 3)
            {
                days++;
            }
            switch (date.m_mon)
            {
            case 1:
                days += 334 + 31 - date.m_day;
                break;
            case 2:
                days += 306 + 28 - date.m_day;
                break;
            case 3:
                days += 275 + 31 - date.m_day;
                break;
            case 4:
                days += 245 + 30 - date.m_day;
                break;
            case 5:
                days += 214 + 31 - date.m_day;
                break;
            case 6:
                days += 184 + 30 - date.m_day;
                break;
            case 7:
                days += 153 + 31 - date.m_day;
                break;
            case 8:
                days += 122 + 31 - date.m_day;
                break;
            case 9:
                days += 92 + 30 - date.m_day;
                break;
            case 10:
                days += 61 + 31 - date.m_day;
                break;
            case 11:
                days += 31 + 30 - date.m_day;
                break;
            case 12:
                days += 31 - date.m_day;
                break;
            default:
                break;
            }
        }
        return -(days);
    }

    // It will return true if the date is valid and false if it is not.
    Date::operator bool() const {
        return m_ErrorCode;
    }

    void Date::currentdate() {
        setToToday();
    }

}