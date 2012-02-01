    namespace fusion
    {
    namespace traits
    {

    template< > struct tag_of< my_struct >
    {
        typedef struct_tag type;
    };

    template< > struct tag_of< my_struct const >
    {
        typedef struct_tag type;
    };
    }
    namespace extension
    {

    template< > struct struct_member< my_struct, 0 >
    {
        typedef int type;

        template<typename Seq> struct apply
        {
            typedef typename add_reference< typename mpl::eval_if< is_const<Seq>, add_const< int >, mpl::identity< int > >::type >::type type;

            static type call(Seq & seq)
            {
                return seq. x;
            }
        };
    };

    template< > struct struct_member_name< my_struct, 0 >
    {
        typedef char const* type;

        static type call()
        {
            return "x";
        }
    };

    template< > struct struct_member< my_struct, 1 >
    {
        typedef int type;

        template<typename Seq> struct apply
        {
            typedef typename add_reference< typename mpl::eval_if< is_const<Seq>, add_const< int >, mpl::identity< int > >::type >::type type;

            static type call(Seq & seq)
            {
                return seq. v;
            }
        };
    };

    template< > struct struct_member_name< my_struct, 1 >
    {
        typedef char const* type;

        static type call()
        {
            return "v";
        }
    };

    template< > struct struct_size< my_struct > : mpl::int_ < 2 >
    {
    };

    template< > struct struct_is_view< my_struct > : mpl::false_
    {
    };
    }
    }
    namespace mpl
    {
    template<typename> struct sequence_tag;

    template< > struct sequence_tag< my_struct >
    {
        typedef fusion::fusion_sequence_tag type;
    };

    template< > struct sequence_tag< my_struct const >
    {
        typedef fusion::fusion_sequence_tag type;
    };
    }
} 
