#include <iostream>
#include <memory>

class Widget {
    public:
        Widget(int val): val(val) {
            std::cout << "Create widget with: " << val << std::endl;
        }

        ~Widget() {
            std::cout << "Remove Widget:" << val << std::endl;
        }

        int val = 0;
};

int main() {
    Widget w_1(1);
    Widget* w_2 = new Widget(2);
    std::unique_ptr<Widget> w_3 = std::make_unique<Widget>(3);
    Widget* w_4 = new Widget(4);
    delete w_4;
    std::cout << "Create in for loop" << std::endl;

    for(int i = 0; i < 10; i++) {
        Widget* w_x = new Widget(i);
        std::unique_ptr<Widget> w_y = std::make_unique<Widget>(100 + i);
    }

    return 0;
}