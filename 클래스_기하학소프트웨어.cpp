#include <iostream>
#include <cmath>
#include <random>


class Point {
  int x, y;

 public:
  Point(int pos_x, int pos_y)
  {
      x = pos_x;
      y = pos_y;
  }

  int getX() const {return x;}
  int getY() const {return y;}
};

class Geometry {
 public:
  Geometry() {
    num_points = 0;
  }

  void AddPoint(const Point &point) {
    point_array[num_points ++] = new Point(point.getX(), point.getY());
  }

  // ��� ���� ���� �Ÿ��� ����ϴ� �Լ� �Դϴ�.
  void PrintDistance();

  // ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ� �Դϴ�.
  // ���������� ������ �� ���� �մ� ������ �������� f(x,y) = ax+by+c = 0
  // �̶�� �� �� ������ �ٸ� �� �� (x1, y1) �� (x2, y2) �� f(x,y)=0 �� ��������
  // ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.
  void PrintNumMeets();

private:
  // �� 100 ���� �����ϴ� �迭.
  Point* point_array[100];
  int num_points;
};

int factorial(int n)
{
    if(n == 0) return 1;
    if(n == 1) return 1;

    else return factorial(n-1) * n;
}

void Geometry::PrintDistance()
{
    float distance = 0;
    float sum_distance = 0;
    int x1=0, y1=0, x2=0, y2=0;

    Point *point1 = NULL, *point2= NULL;


    for (int i=0; i < num_points; i++)
    {
        for (int j = i+1; j < num_points; j++)
        {
            point1 = point_array[i];
            point2 = point_array[j];

            x1 = point1->getX(), x2=point2->getX();
            y1 = point1->getY(), y2=point2->getY();
            
            distance = pow(pow(x1-x2, 2) + pow(y1-y2, 2), 0.5);

            std::cout << "Point["<< i+1 <<"] : (" << x1 << "," << y1 << ")" << std::endl;
            std::cout << "Point["<< j+1 <<"] : (" << x2 << "," << y2 << ")" << std::endl;
            std::cout << "Point["<< i+1 <<"]�� Point["<< j+1 <<"]�� �Ÿ� : " << distance << std::endl;
            std::cout << std::endl;

            sum_distance += distance;
        }
    }

    std::cout << "��� ���� ���� �Ÿ��� ���� "<< sum_distance << "�Դϴ�." << std::endl;
}

void Geometry::PrintNumMeets()
{
    const int num_of_lines = (pow(num_points,2) - num_points) / 2; // ��� ������ �մ� ������ ���� 

    std::cout << "��� ������ �մ� ������ ������ "<< num_of_lines <<"�� �Դϴ�." << std::endl;

    int coefficients[10000][5] = {0,};

    // ù��°[0] : ������ ������ ��� a
    // �ι�°[1] : ������ ������ ��� b
    // ����°[2] : ������ ������ ��� c
    // �׹�°[3] : ������ �������� ����� point1�� index
    // �ټ���°[4] : ������ �������� ����� point2�� index

    // ������ ������ ���ϱ�

    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int nth_line = 0;


    for (int i=0; i<num_points; i++)
    {
        for(int j = i+1; j < num_points; j++)
        {
            x1 = point_array[i]->getX();
            y1 = point_array[i]->getY();
            x2 = point_array[j]->getX();
            y2 = point_array[j]->getY();

            coefficients[nth_line][0] = y2 - y1;
            coefficients[nth_line][1] = x1 - x2;
            coefficients[nth_line][2] = x1*y1 - 2*x1*y2 + x2*y2; 
            coefficients[nth_line][3] = y2 - y1;
            coefficients[nth_line][4] = y2 - y1;
            nth_line++;
        }
    }

    int sum_of_meets = 0; 

    for (int i=0; i<num_of_lines-1; i++)
    {
        for (int j=0; j<num_points; j++)
        {
            for(int k=j+1; k<num_points; k++)
            {
                x1 = point_array[j]->getX();
                y1 = point_array[j]->getY();
                x2 = point_array[k]->getX();
                y2 = point_array[k]->getY();

                if ((coefficients[i][0]*x1 + coefficients[i][1]*y1 + coefficients[i][2]) * (coefficients[i][0]*x2 + coefficients[i][1]*y2 + coefficients[i][2]) <= 0) 
                    sum_of_meets++;
            }
        }
    }

    std::cout << std::endl;
    std::cout << "������ ������ " << num_of_lines << "�� �Դϴ�." << std::endl;
    std::cout << "������ �������� ��� ������ ������ " << sum_of_meets << "�� �̴�." << std::endl;
}




int main() 
{
    Point pos1(1, 2), pos2(3, 1), pos3(-1, -4), pos4(5,2);
	Geometry Geo;
	Geo.AddPoint(pos1);
	Geo.AddPoint(pos2);
	Geo.AddPoint(pos3);
	Geo.AddPoint(pos4);

	Geo.PrintDistance();
	Geo.PrintNumMeets();

	return 0;
}