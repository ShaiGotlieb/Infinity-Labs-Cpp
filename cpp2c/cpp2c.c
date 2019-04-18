#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */

#define UNUSED(x) (void)(x)
#define MAX_FUNC(t1, t2) (((t1 > t2) ? t1 : t2))

static int s_count;

struct PublicTransportFuncPtr;
struct MinibusFuncPtr;
struct TaxiFuncPtr;
struct SpecialTaxiFuncPtr;
struct PublicTransport;
struct Minibus;
struct Taxi;
struct SpecialTaxi;

/* structs pointers to functions */
struct PublicTransportFuncPtr
{
    void (*Dtor)(struct PublicTransport * const publicTransport);
    void (*display)(struct PublicTransport * const publicTransport);
};

struct MinibusFuncPtr
{
    void (*Dtor)(struct Minibus * const minibus);
    void (*display)(struct Minibus * const minibus);
    void (*wash)(struct Minibus * const minibus, int minutes);
};

struct TaxiFuncPtr
{
    void (*Dtor)(struct Taxi const * taxi);   
    void (*display)(struct Taxi * const taxi); 
};

struct SpecialTaxiFuncPtr
{
    void (*Dtor)(struct SpecialTaxi * const specialTaxi);
    void (*display)(struct SpecialTaxi const * specialTaxi);
};

/* structs */
struct PublicTransport
{
    struct PublicTransportFuncPtr *funcs;
    int m_license_plate;
};

struct Minibus
{
    struct PublicTransportFuncPtr *funcs;
    int m_license_plate;
    int m_numSeats;
};

struct Taxi
{
    struct PublicTransportFuncPtr *funcs;
    int m_license_plate;
};

struct SpecialTaxi
{
    struct PublicTransportFuncPtr *funcs;
    int m_license_plate;
};


/* forward declerations */
int get_ID(struct PublicTransport * const publicTransport);
static void print_count();
void print_info_recieve_PublicTransport(struct PublicTransport *a);
void print_info_recieve_void();
void print_info_recieve_Minibus(struct Minibus *m);
struct PublicTransport print_info_recieve_int_ret_PublicTransport(int i);
void display(struct PublicTransport * const publicTransport);
void MinibusCCtor(struct Minibus * const minibus, struct Minibus * const other); 
void MinibusCtor(struct Minibus * const minibus);
void MinibusDisplay(struct Minibus * const minibus);
void MinibusDtor(struct Minibus * const minibus);
void MinibusWash(struct Minibus * const minibus, int minutes);
void PublicTransportCCtor(struct PublicTransport * const publicTransport, struct PublicTransport * const other);
void PublicTransportCtor(struct PublicTransport * const publicTransport);
void PublicTransportDtor(struct PublicTransport * const publicTransport);
void TaxiCCtor(struct Taxi * const taxi, struct Taxi *other);
void TaxiCtor(struct Taxi * const taxi);
void TaxiDisplay(struct Taxi * const taxi);
void TaxiDtor(struct Taxi const * taxi);
void SpecialTaxiCtor(struct SpecialTaxi * const specialTaxi);
void SpecialTaxiCCtor(struct SpecialTaxi * const specialTaxi, struct SpecialTaxi * const other);
void SpecialTaxiDtor(struct SpecialTaxi * const specialTaxi);
void SpecialTaxiDisplay(struct SpecialTaxi const * specialTaxi);

/* Init v_tables */
struct PublicTransportFuncPtr publicTransport_v_table = 
{ 
    PublicTransportDtor, 
    display
};

struct MinibusFuncPtr minibus_v_table = 
{
    MinibusDtor,
    MinibusDisplay,
    MinibusWash

};

struct TaxiFuncPtr taxi_v_table = 
{
    TaxiDtor,
    TaxiDisplay
};

struct SpecialTaxiFuncPtr specialTaxi_v_table = 
{
    SpecialTaxiDtor,
    SpecialTaxiDisplay
};

/*----------------PublicTransport-----------------*/
/* CTOR */
void PublicTransportCtor(struct PublicTransport * const publicTransport)
{
    ++s_count;
    publicTransport->m_license_plate = s_count;
    publicTransport->funcs = &publicTransport_v_table;
    printf("PublicTransport::Ctor() %d\n", publicTransport->m_license_plate);
}

/* CCTOR */
void PublicTransportCCtor(struct PublicTransport * const publicTransport, struct PublicTransport * const other)
{
    UNUSED(other);
    publicTransport->m_license_plate = ++s_count;
    publicTransport->funcs = &publicTransport_v_table;
    printf("PublicTransport::CCtor() %d\n", publicTransport->m_license_plate);
}

/* DTOR */
void PublicTransportDtor(struct PublicTransport * const publicTransport)
{
    --s_count;
    printf("PublicTransport::Dtor() %d\n", publicTransport->m_license_plate);
}

/* member function of PublicTransport */
void display(struct PublicTransport * const publicTransport)
{
    printf("PublicTransport::display(): %d\n", publicTransport->m_license_plate);
}

/* member function of PublicTransport */
static void print_count()
{
    printf("s_count: %d\n", s_count);
}

/* member function of PublicTransport */
int get_ID(struct PublicTransport * const publicTransport)
{
    return publicTransport->m_license_plate;
}

/* -----------------Minibus--------------------*/

/* CTOR */
void MinibusCtor(struct Minibus * const minibus)
{
    PublicTransportCtor((struct PublicTransport*)minibus);
    minibus->m_numSeats = 20;
    minibus->funcs = (struct PublicTransportFuncPtr*)&minibus_v_table;
    printf("Minibus::Ctor()\n");
}

/* CCTOR */
void MinibusCCtor(struct Minibus * const minibus, struct Minibus * const other)
{
    PublicTransportCCtor((struct PublicTransport*)minibus, (struct PublicTransport*)other);
    minibus->m_numSeats = other->m_numSeats;
    minibus->funcs = (struct PublicTransportFuncPtr*)&minibus_v_table;
    printf("Minibus::CCtor() \n");
}

/* DTOR */
void MinibusDtor(struct Minibus * const minibus)
{
    printf("Minibus::Dtor()\n");
    PublicTransportDtor((struct PublicTransport *)minibus);
}

/* member function of Minibus */
void MinibusDisplay(struct Minibus * const minibus)
{
    printf("Minibus::display() ID: %d", get_ID((struct PublicTransport*)minibus));
    printf(" num seats: %d\n", minibus->m_numSeats);
}

void MinibusWash(struct Minibus * const minibus, int minutes)
{
    printf("Minibus::wash( %d ) ID: %d\n", minutes, get_ID((struct PublicTransport*)minibus));
}

/*-----------------------Taxi----------------------*/

/* CTOR */
void TaxiCtor(struct Taxi * const taxi)
{
    PublicTransportCtor((struct PublicTransport*)taxi);
    taxi->funcs = (struct PublicTransportFuncPtr*)&taxi_v_table;
    printf("Taxi::Ctor()\n");
}

/* CCTOR */
void TaxiCCtor(struct Taxi * const taxi, struct Taxi *other)
{
    PublicTransportCCtor((struct PublicTransport*)taxi, (struct PublicTransport*)other);
    taxi->funcs = (struct PublicTransportFuncPtr*)&taxi_v_table;
    printf("Taxi::CCtor()\n");
}

/* DTOR */
void TaxiDtor(struct Taxi const * taxi)
{
    printf("Taxi::Dtor()\n");
    PublicTransportDtor((struct PublicTransport*)taxi);
}

/* member function of Taxi */
void TaxiDisplay(struct Taxi * const taxi)
{
    printf("Taxi::display() ID: %d\n", get_ID((struct PublicTransport*)taxi));
}

/*------------------SpecialTaxi--------------------*/

/* CTOR */
void SpecialTaxiCtor(struct SpecialTaxi * const specialTaxi)
{
    TaxiCtor((struct Taxi*)specialTaxi);
    specialTaxi->funcs = (struct PublicTransportFuncPtr*)&specialTaxi_v_table;
    printf("SpecialTaxi::Ctor()\n");
}

/* CCTOR */
void SpecialTaxiCCtor(struct SpecialTaxi * const specialTaxi, struct SpecialTaxi * const other)
{
    TaxiCCtor((struct Taxi *)specialTaxi, (struct Taxi *)other);
    specialTaxi->funcs = (struct PublicTransportFuncPtr*)&specialTaxi_v_table;
    printf("SpecialTaxi::CCtor()\n");
}

/* DTOR */
void SpecialTaxiDtor(struct SpecialTaxi * const specialTaxi)
{
    printf("SpecialTaxi::Dtor()\n");
    TaxiDtor((struct Taxi*)specialTaxi);
}

/* member function of SpecialTaxi */
void SpecialTaxiDisplay(struct SpecialTaxi const * specialTaxi)
{
    printf("SpecialTaxi::display() ID: %d\n", get_ID((struct PublicTransport*)specialTaxi));
}

/*-----------------global functions------------------*/

void print_info_recieve_PublicTransport(struct PublicTransport *a)
{
    a->funcs->display(a);
}

void print_info_recieve_void()
{
    print_count();
}

void print_info_recieve_Minibus(struct Minibus *m)
{
    MinibusWash(m, 3);
}

struct PublicTransport print_info_recieve_int_ret_PublicTransport(int i)
{
    struct Minibus ret;
    struct PublicTransport publicTransport;

    UNUSED(i);
    MinibusCtor(&ret);
    printf("print_info(int i)\n");
    ret.funcs->display((struct PublicTransport*)&ret);
    PublicTransportCCtor(&publicTransport, (struct PublicTransport*)&ret);
    MinibusDtor(&ret);

    return publicTransport;
}

void taxi_display(struct Taxi s)
{
    s.funcs->display((struct PublicTransport*)&s);
}

/*------------main-------------*/
int main(int argc, char **argv, char **envp)
{
    struct Minibus m;
    struct Minibus *m1;
    struct Minibus *m2;
    struct Minibus m214;
    struct Minibus m205;
    struct Minibus arr3[4];
    struct PublicTransport pub_trans;
    struct PublicTransport pub_trans205;
    struct PublicTransport *array[3];
    struct PublicTransport arr2[3];
    struct Taxi *taxi1;
    struct Taxi taxi205;
    struct Taxi *arr4;
    struct Taxi copy_special_taxi;
    struct SpecialTaxi st;
    int i = 0;

    MinibusCtor(&m);

    /*line 193: print_info(m); */
    print_info_recieve_Minibus(&m);

    /*line 194: print_info(3).display(); */ 
    pub_trans = print_info_recieve_int_ret_PublicTransport(3);
    pub_trans.funcs->display(&pub_trans);
    pub_trans.funcs->Dtor(&pub_trans);

    /*line 195: PublicTransport *array[] = { new Minibus(), new Taxi(), new Minibus() }; */
    m1 = malloc(sizeof(struct Minibus));
    taxi1 = malloc(sizeof(struct Taxi));
    m2 = malloc(sizeof(struct Minibus));

    MinibusCtor(m1);
    TaxiCtor(taxi1);
    MinibusCtor(m2);
    array[0] = (struct PublicTransport*)m1;
    array[1] = (struct PublicTransport*)taxi1;
    array[2] = (struct PublicTransport*)m2;
    /* end line 195 */

    /*line 197: for (int i = 0; i < 3; ++i) { array[i]->display();}*/
    for (i = 0; i < 3; ++i) {
        array[i]->funcs->display(array[i]);
    }

    for (i = 0; i < 3; ++i) 
    {
        array[i]->funcs->Dtor(array[i]);
        free(array[i]);
    }
    /* end line 197 */

    /*line 205: PublicTransport arr2[] = { Minibus(), Taxi(), PublicTransport() };*/
    MinibusCtor(&m205);
    PublicTransportCCtor((struct PublicTransport*)&arr2[0], (struct PublicTransport*)&m205);
    m205.funcs->Dtor((struct PublicTransport*)&m205);

    TaxiCtor(&taxi205);
    PublicTransportCCtor((struct PublicTransport*)&arr2[1], (struct PublicTransport*)&taxi205);
    taxi205.funcs->Dtor((struct PublicTransport*)&taxi205);

    PublicTransportCtor(&arr2[2]);
    /*end line 205 */

    /*line 207: for (int i = 0; i < 3; ++i) {arr2[i].display(); }*/
    for (i = 0; i < 3; ++i) 
    {
        arr2[i].funcs->display(&arr2[i]);
    }
    /*end line 207*/

    /* line 211: print_info(arr2[0]);*/
    print_info_recieve_PublicTransport(&arr2[0]);

    /*line 213: PublicTransport::print_count();*/
    print_count();

    /*line 214-215: Minibus m2;   m2.print_count();*/
    MinibusCtor(&m214);
    print_count();

    /*line 217: Minibus arr3[4]; */
    MinibusCtor(arr3);
    MinibusCtor(&arr3[1]);
    MinibusCtor(&arr3[2]);
    MinibusCtor(&arr3[3]);

    /*line 218: axi *arr4 = new Taxi[4]; */
    arr4 = malloc(sizeof(struct Taxi) * 4);
    free(arr4);

    /*line 221 - 222:     std::cout << max_func(1, 2) << "\n"; 
                        std::cout << max_func<int>(1, 2.0f)<< "\n";*/
    printf("%d\n", MAX_FUNC(1,2));
    printf("%d\n", MAX_FUNC(1,(int)2.0));

    /*line 223: SpecialTaxi st; */
    SpecialTaxiCtor(&st);
    TaxiCCtor(&copy_special_taxi, (struct Taxi*)&st);


    /*line 224: taxi_display(st); */
    taxi_display(copy_special_taxi);

    /*Dtor's*/
    copy_special_taxi.funcs->Dtor((struct PublicTransport*)&copy_special_taxi);
    st.funcs->Dtor((struct PublicTransport*)&st);
    arr3[0].funcs->Dtor((struct PublicTransport*)&arr3[3]);
    arr3[0].funcs->Dtor((struct PublicTransport*)&arr3[2]);
    arr3[0].funcs->Dtor((struct PublicTransport*)&arr3[1]);
    arr3[0].funcs->Dtor((struct PublicTransport*)&arr3[0]);
    m214.funcs->Dtor((struct PublicTransport*)&m214);
    arr2[2].funcs->Dtor(&arr2[2]);
    arr2[1].funcs->Dtor((struct PublicTransport*)&arr2[1]);
    arr2[0].funcs->Dtor((struct PublicTransport*)&arr2[0]);
    m.funcs->Dtor((struct PublicTransport*)&m);
    
    UNUSED(argc);
    UNUSED(argv);
    UNUSED(envp);
    return 0;
}