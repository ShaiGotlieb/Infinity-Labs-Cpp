#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */

#define UNUSED(x) (void)(x)

int g_s_count;

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
    void (*Dtor)(struct PublicTransport * const this);
    void (*display)(struct PublicTransport * const this);
};

struct MinibusFuncPtr
{
    void (*Dtor)(struct Minibus * const this);
    void (*display)(struct Minibus * const this);
    void (*wash)(struct Minibus * const this, int minutes);
};

struct TaxiFuncPtr
{
    void (*Dtor)(struct Taxi const * this);   
    void (*display)(struct Taxi * const this); 
};

struct SpecialTaxiFuncPtr
{
    void (*Dtor)(struct SpecialTaxi * const this);
    void (*display)(struct SpecialTaxi const * this);
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
int get_ID(struct PublicTransport * const this);
static void print_count();
void print_info_recieve_PublicTransport(struct PublicTransport *a);
void print_info_recieve_void();
void print_info_recieve_Minibus(struct Minibus *m);
struct PublicTransport print_info_recieve_int_ret_PublicTransport(int i);
void display(struct PublicTransport * const this);
void MinibusCCtor(struct Minibus * const this, struct Minibus * const other); 
void MinibusCtor(struct Minibus * const this);
void MinibusDisplay(struct Minibus * const this);
void MinibusDtor(struct Minibus * const this);
void MinibusWash(struct Minibus * const this, int minutes);
void PublicTransportCCtor(struct PublicTransport * const this, struct PublicTransport * const other);
void PublicTransportCtor(struct PublicTransport * const this);
void PublicTransportDtor(struct PublicTransport * const this);
void TaxiCCtor(struct Taxi * const this, struct Taxi *other);
void TaxiCtor(struct Taxi * const this);
void TaxiDisplay(struct Taxi * const this);
void TaxiDtor(struct Taxi const * this);
void SpecialTaxiCtor(struct SpecialTaxi * const this);
void SpecialTaxiCCtor(struct SpecialTaxi * const this, struct SpecialTaxi * const other);
void SpecialTaxiDtor(struct SpecialTaxi * const this);
void SpecialTaxiDisplay(struct SpecialTaxi const * this);
void* operator_new(size_t size);
void operator_delete(void *object_to_remove);

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
void PublicTransportCtor(struct PublicTransport * const this)
{
    this->funcs = &publicTransport_v_table;
    this->m_license_plate = ++g_s_count;
    printf("PublicTransport::Ctor() %d\n", this->m_license_plate);
}

/* CCTOR */
void PublicTransportCCtor(struct PublicTransport * const this, struct PublicTransport * const other)
{
    UNUSED(other);
    this->funcs = &publicTransport_v_table;
    this->m_license_plate = ++g_s_count;
    printf("PublicTransport::CCtor() %d\n", this->m_license_plate);
}

/* DTOR */
void PublicTransportDtor(struct PublicTransport * const this)
{
    --g_s_count;
    printf("PublicTransport::Dtor() %d\n", this->m_license_plate);
}

/* member function of PublicTransport */
void display(struct PublicTransport * const this)
{
    printf("PublicTransport::display(): %d\n", this->m_license_plate);
}

/* member function of PublicTransport */
static void print_count()
{
    printf("g_s_count: %d\n", g_s_count);
}

/* member function of PublicTransport */
int get_ID(struct PublicTransport * const this)
{
    return this->m_license_plate;
}

/* -----------------Minibus--------------------*/

/* CTOR */
void MinibusCtor(struct Minibus * const this)
{
    PublicTransportCtor((struct PublicTransport*)this);
    this->funcs = (struct PublicTransportFuncPtr*)&minibus_v_table;
    this->m_numSeats = 20;
    printf("Minibus::Ctor()\n");
}

/* CCTOR */
void MinibusCCtor(struct Minibus * const this, struct Minibus * const other)
{
    PublicTransportCCtor((struct PublicTransport*)this, (struct PublicTransport*)other);
    this->funcs = (struct PublicTransportFuncPtr*)&minibus_v_table;
    this->m_numSeats = other->m_numSeats;
    printf("Minibus::CCtor() \n");
}

/* DTOR */
void MinibusDtor(struct Minibus * const this)
{
    printf("Minibus::Dtor()\n");
    PublicTransportDtor((struct PublicTransport *)this);
}

/* member function of Minibus */
void MinibusDisplay(struct Minibus * const this)
{
    printf("Minibus::display() ID: %d", get_ID((struct PublicTransport*)this));
    printf(" num seats: %d\n", this->m_numSeats);
}

void MinibusWash(struct Minibus * const this, int minutes)
{
    printf("Minibus::wash( %d ) ID: %d\n", minutes, get_ID((struct PublicTransport*)this));
}

/*-----------------------Taxi----------------------*/

/* CTOR */
void TaxiCtor(struct Taxi * const this)
{
    PublicTransportCtor((struct PublicTransport*)this);
    this->funcs = (struct PublicTransportFuncPtr*)&taxi_v_table;
    printf("Taxi::Ctor()\n");
}

/* CCTOR */
void TaxiCCtor(struct Taxi * const this, struct Taxi *other)
{
    PublicTransportCCtor((struct PublicTransport*)this, (struct PublicTransport*)other);
    this->funcs = (struct PublicTransportFuncPtr*)&taxi_v_table;
    printf("Taxi::CCtor()\n");
}

/* DTOR */
void TaxiDtor(struct Taxi const * this)
{
    printf("Taxi::Dtor()\n");
    PublicTransportDtor((struct PublicTransport*)this);
}

/* member function of Taxi */
void TaxiDisplay(struct Taxi * const this)
{
    printf("Taxi::display() ID: %d\n", get_ID((struct PublicTransport*)this));
}

/*------------------SpecialTaxi--------------------*/

/* CTOR */
void SpecialTaxiCtor(struct SpecialTaxi * const this)
{
    TaxiCtor((struct Taxi*)this);
    this->funcs = (struct PublicTransportFuncPtr*)&specialTaxi_v_table;
    printf("SpecialTaxi::Ctor()\n");
}

/* CCTOR */
void SpecialTaxiCCtor(struct SpecialTaxi * const this, struct SpecialTaxi * const other)
{
    TaxiCCtor((struct Taxi *)this, (struct Taxi *)other);
    this->funcs = (struct PublicTransportFuncPtr*)&specialTaxi_v_table;
    printf("SpecialTaxi::CCtor()\n");
}

/* DTOR */
void SpecialTaxiDtor(struct SpecialTaxi * const this)
{
    printf("SpecialTaxi::Dtor()\n");
    TaxiDtor((struct Taxi*)this);
}

/* member function of SpecialTaxi */
void SpecialTaxiDisplay(struct SpecialTaxi const * this)
{
    printf("SpecialTaxi::display() ID: %d\n", get_ID((struct PublicTransport*)this));
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
    ((struct MinibusFuncPtr *)m->funcs)->wash(m, 3);
}

struct PublicTransport print_info_recieve_int_ret_PublicTransport(int i)
{
    struct Minibus ret;
    struct PublicTransport publicTransport;

    UNUSED(i);
    MinibusCtor(&ret);
    printf("print_info(int i)\n");
    MinibusDisplay(&ret);
    PublicTransportCCtor(&publicTransport, (struct PublicTransport*)&ret);
    MinibusDtor(&ret);

    return publicTransport;
}

void taxi_display(struct Taxi s)
{
    s.funcs->display((struct PublicTransport*)&s);
}

void operator_delete(void *object_to_remove)
{
    free(object_to_remove);
}

void* operator_new(size_t size)
{
    return malloc(sizeof(size));
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
    display(&pub_trans);
    pub_trans.funcs->Dtor(&pub_trans);

    /*line 195: PublicTransport *array[] = { new Minibus(), new Taxi(), new Minibus() }; */
    m1 = operator_new(sizeof(struct Minibus));
    taxi1 = operator_new(sizeof(struct Taxi));
    m2 = operator_new(sizeof(struct Minibus));

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
        operator_delete(array[i]);
    }
    /* end line 197 */

    /*line 205: PublicTransport arr2[] = { Minibus(), Taxi(), PublicTransport() };*/
    MinibusCtor(&m205);
    PublicTransportCCtor(&arr2[0], (struct PublicTransport*)&m205);
    m205.funcs->Dtor((struct PublicTransport*)&m205);
    TaxiCtor(&taxi205);
    PublicTransportCCtor((struct PublicTransport*)&arr2[1], (struct PublicTransport*)&taxi205);
    taxi205.funcs->Dtor((struct PublicTransport*)&taxi205);
    PublicTransportCtor(&arr2[2]);
    /*end line 205 */

    /*line 207: for (int i = 0; i < 3; ++i) {arr2[i].display(); }*/
    for (i = 0; i < 3; ++i) 
    {
        display(&arr2[i]);
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
    arr4 = operator_new(sizeof(struct Taxi) * 4);
    operator_delete(arr4);

    printf("%d\n",2);
    printf("%d\n",2); /* inline!*/

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