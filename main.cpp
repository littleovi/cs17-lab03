#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;
 enum Scale{
 Kelvin = 'K', Celcium = 'C', Farengheite = 'F'
 };
 struct tempreture{
    Scale scale;
    double value;
};

istream& operator >> (istream& in, tempreture& t){
 in >> t.value;
    char symbol;
    in >> symbol;
    switch(symbol){
    case 'K':
        t.scale=Kelvin;
        break;
    case 'C':
        t.scale=Celcium;
        break;
    case 'F':
        t.scale=Farengheite;
        break;
    }
    return in;
}
void test_tempreture_input(){
    stringstream in ("17C");
    tempreture t;
    in>> t;
    assert(t.value == 17);
    assert(t.scale == Celcium);

    stringstream im ("-66F");
    im>> t;
    assert(t.value == -66);
    assert(t.scale == Farengheite);

    stringstream is ("28K");
    is>> t;
    assert(t.value == 28);
    assert(t.scale == Kelvin);
}
  tempreture  convert(const tempreture& from, Scale scale){
      double K;
      switch(from.scale){
      case Kelvin:
          K =  from.value;
          break;
      case Celcium:
          K =  from.value+273,15;
          break;
      case Farengheite:
          K = (from.value+459,67)/1.8;
          break;
      }
      tempreture result;
      result.scale = scale;
      switch(scale){
      case Kelvin:
          result.value = Kelvin;
          break;
      case Celcium:
          result.value = Kelvin-273,15;
      break;
      case Farengheite:
          result.value = (Kelvin*1,8)-459,67;
      break;
      }
      return result;
      //switch по шкале температуры  from,
      // рассчитать K
      //switch о шкале to
      //рассчитать значение результата
  };
bool operator < (tempreture& lhs,tempreture& rhs) {
    tempreture t ;
    t = convert(lhs, rhs.scale);
    return t.value < rhs.value ;

}
int
main() {
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<tempreture> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    tempreture min = numbers[0];
    tempreture  max = numbers[0];
    for (tempreture number : numbers) {
        if (number < min) {
            min = number;
        }
        if (max < number ) {
            max = number;
        }
    }
    max= convert(max,min.scale);
    vector<size_t> counts(column_count);
    for (tempreture number : numbers) {
        number= convert(number, min.scale);
        size_t column = (size_t)((number.value - min.value ) / (max.value - min.value) *
                column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // Можно было бы считать в предыдущем цикле, но так более наглядно.
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            // Point: код должен быть в первую очередь понятным.
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}