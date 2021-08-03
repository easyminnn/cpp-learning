#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date)
  {
      year_ = year;
      month_ = month;
      day_ = date;
  }

  void AddDay(int inc)
  {
    int daynum[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      
    for (int i=0; i<inc; i++)
    {
        day_++;
        if(daynum[month_-1] < day_)
        {
            day_ = 1; 
            month_++;
            if(month_ > 12)
            {
                month_ = 1;
                year_ ++;
            }
        }
    }
  }

  void AddMonth(int inc);
  void AddYear(int inc);



  void ShowDate()
  {
      std::cout<<year_<<"년 "<<month_<<"월 "<<day_<<"일"<<std::endl;
  }
};





int main()
{
    Date date;

    date.SetDate(2021, 8, 2);
    date.ShowDate();

    date.AddDay(11);
	date.ShowDate();

	date.AddDay(13);
    date.ShowDate();

    date.AddDay(5);
    date.ShowDate();

    date.AddDay(1);
    date.ShowDate();

    date.AddDay(30);
    date.ShowDate();
        
    date.AddDay(31);
    date.ShowDate();

    date.AddDay(31);
    date.ShowDate();

    date.AddDay(30);
    date.ShowDate();
}