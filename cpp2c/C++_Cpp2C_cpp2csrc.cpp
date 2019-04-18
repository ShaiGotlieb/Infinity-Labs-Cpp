#include <iostream> //cout
using namespace std;

class PublicTransport {
public:
    PublicTransport() : m_license_plate(++s_count)
    {
        cout << "PublicTransport::Ctor()" << m_license_plate << "\n";
    }

    virtual ~PublicTransport() //V
    {
        --s_count;
        cout << "PublicTransport::Dtor()" << m_license_plate << "\n";
    }

    PublicTransport(const PublicTransport &other) : m_license_plate(++s_count)//V
    {
        cout << "PublicTransport::CCtor() " << m_license_plate << "\n";
    }

    virtual void display() //V
    {
        cout << "PublicTransport::display(): " << m_license_plate << "\n";
    }

    static void print_count()//V
    {
        cout << "s_count: " << s_count << "\n";
    }
protected:
    int get_ID()//V
    {
        return m_license_plate;
    }

private:
    static int s_count;
    int m_license_plate;
    PublicTransport &operator=(const PublicTransport &); // disabled
};

int PublicTransport::s_count = 0;

class Minibus: public PublicTransport {
public:
    Minibus() : m_numSeats(20) //V
    {
        cout << "Minibus::Ctor()\n";
    }

    Minibus(const Minibus &other) : PublicTransport(other),
                                    m_numSeats(other.m_numSeats) //V
    {
        cout << "Minibus::CCtor()\n";
    }

    ~Minibus() //virtual? it is in its base //V
    {
        cout << "Minibus::Dtor()\n";
    }

    void display() //virtual? it is in its base //V
    {
        cout << "Minibus::display() ID:" << get_ID();
        cout << " num seats:" << m_numSeats << "\n";
    }

    virtual void wash(int minutes) //V
    {
        cout << "Minibus::wash(" << minutes << ") ID:" << get_ID() << "\n";
    }

private:
    int m_numSeats;
};

class Taxi: public PublicTransport {
public:
    Taxi() //V
    {
        cout << "Taxi::Ctor()\n";
    }

    Taxi(const Taxi &other) : PublicTransport(other) //V
    {
        cout << "Taxi::CCtor()\n";
    }

    ~Taxi() //V
    {
        cout << "Taxi::Dtor()\n";
    }

    void display() //V
    {
        cout << "Taxi::display() ID:" << get_ID() << "\n";
    }

private:
};

template<class T>
inline T max_func(const T &t1, const T &t2)
{
    return ((t1 > t2) ? t1 : t2);
}

/**/class SpecialTaxi: public Taxi {
public:
    SpecialTaxi()
    {
        cout << "SpecialTaxi::Ctor()\n";
    }

    SpecialTaxi(const SpecialTaxi &other) : Taxi(other)
    {
        cout << "SpecialTaxi::CCtor()\n";
    }

    ~SpecialTaxi()
    {
        cout << "SpecialTaxi::Dtor()\n";
    }

    void display()
    {
        cout << "SpecialTaxi::display() ID:" << get_ID() << "\n";
    }
private:
};

// class PublicConvoy: public PublicTransport {
// public:
//     PublicConvoy() : m_pt1(new Minibus()), m_pt2(new Taxi())
//     {
//     }

//     ~PublicConvoy()
//     {
//         delete m_pt1;
//         delete m_pt2;
//     }

//     void display()
//     {
//         m_pt1->display();
//         m_pt2->display();
//         m_m.display();
//         m_t.display();
//     }

// private:
//     PublicTransport *m_pt1;
//     PublicTransport *m_pt2;
//     Minibus m_m;
//     Taxi m_t;
// };

void print_info(PublicTransport &a)//V
{
    a.display();
}


void print_info()//V
{
    PublicTransport::print_count();
}

void print_info(Minibus &m)//V
{
    m.wash(3);
}


PublicTransport print_info(int i)//V
{
    Minibus ret;
    cout << "print_info(int i)\n";
    ret.display();
    return ret;
}

void taxi_display(Taxi s)//V
{
    s.display();
}

int main(int argc, char **argv, char **envp)
{
    Minibus m;
    print_info(m);
    print_info(3).display();
    PublicTransport *array[] = { new Minibus(), new Taxi(), new Minibus() };

    for (int i = 0; i < 3; ++i) {
        array[i]->display();
    }

    for (int i = 0; i < 3; ++i) {
        delete array[i];
    }

    PublicTransport arr2[] = { Minibus(), Taxi(), PublicTransport() };

    for (int i = 0; i < 3; ++i) {
        arr2[i].display();
    }

    print_info(arr2[0]);

    PublicTransport::print_count();
    Minibus m2;
    m2.print_count();

    Minibus arr3[4];
    Taxi *arr4 = new Taxi[4];
    delete[] arr4;

    std::cout << max_func(1, 2) << "\n";
    std::cout << max_func<int>(1, 2.0f)<< "\n";
    SpecialTaxi st;
    taxi_display(st);
//-----------in comments
    // PublicConvoy *ts1 = new PublicConvoy();
    // PublicConvoy *ts2 = new PublicConvoy(*ts1);
    // ts1->display();
    // ts2->display();
    // delete ts1;
    // ts2->display();
    // delete ts2;

    return 0;
}
