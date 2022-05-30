// clang-format off
# 有一个奇怪的写法：
      template<class T>
      void fun() requires( requires(parameter-list){requirement-seq} ){};

# 这么写的理由如下：
# noexcept VS requires
    # We have both expression and clause:
        # For noexcept:
          ==>clause:
            void fun() noexcept(......);
          ==>expression:
            constexpr bool val = noexcept(......);

        # For requires:
          ==>clause:
            void fun() requires(......);
          ==>expression:
            constexpr bool val = requires(parameter-list){requirement-seq};

        # Noexcept-clause contains a noexcept-expression:
            template<class T>
            void fun() noexcept(noexcept(......));
            ==
            template<class T>
            constexpr bool val = noexcept(......);

            template<class T>
            void fun() noexcept(val<T>);
  
        # Requires-clause contains a requires-expression:
            template<class T>
            void fun() requires( requires(parameter-list){requirement-seq} ){};
            ==
            template<class T>
            concept val = requires(parameter-list){requirement-seq};

            template<class T>
            void fun() requires val<T>{};
// clang-format on

// clang-format off
# How to write an requires expression:
    template<class T> 
    concept Fooable = requires(parameter-list)
    {
        typename T::value_type;
        {value-expression};
        {value-expression} noexcept;
        {value-expression} ->type-constraint;
        requires constraint-expression;
    };
#example:
    template<class T>
    concept Fooable = requires (const T ct, int i) {
    typename T::value_type;
    { ct + i };  //千万注意这个是大括号！！

    { ct += i } noexcept;
    { ct - ct } -> std::integral;
    
    //equivalent to: { ct += i } noexcept;
    requires noexcept(ct += i);
    //equivalent to: { ct - ct } -> std::integral;
    requires std::integral<decltype((ct - ct))>;

    };
// clang-format on
