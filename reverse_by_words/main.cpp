#include <iostream>

template <typename Iter>
void reverse_by_symbol( Iter first, Iter last ) {
    for( auto i = first, j = last; i != j; ++i ) {
        --j;
        std::iter_swap( i, j );
        if( i == j ) {
            break;
        }
    }
}

template< typename Iter >
void reverse_by_words( Iter first, Iter last )
{
    reverse_by_symbol( first, last );
    auto i = first, j = first;
    for( ; i != last; ++i ) {
        if( *j == ' ' ) {
            j = i;
        }
        else if( *i == ' ' ) {
            reverse_by_symbol( j, i );
            j = i;
        }
    }
    
    reverse_by_symbol( j, i );
}

int main(int argc, const char * argv[]) {
    
    for( std::string line; std::getline( std::cin , line ); ) {
        reverse_by_words( line.begin(), line.end() );
        std::cout << line << std::endl;
    }
    
    return 0;
}
