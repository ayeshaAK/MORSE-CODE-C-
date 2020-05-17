char *convertToString( char *sequence )
{
    char Alphabets_Letters [45] = { 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L', 'M',
    'N', 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z' , '0' , '1' , '2' , '3' , '4' ,
    '5' , '6' , '7' , '8' , '9' , '.' , ',' , '?' , '`' , '!' , '/' , '(' , ')' , '&' } ;

    char morse_character_code [45][7] = { ".-" , "-..." , "-.-." , "-.." , "." , "..-." , "--." , "...." , ".." , ".---" ,
    "-.-" , ".-.." , "--" , "-." , "---" , ".--." , "--.-" , ".-." , "..." , "-" , "..-" , "...-" , ".--" , "-..-" , "-.--" ,
    "--.." , "-----" , ".----" , "..---" , "...--" , "....-" , "....." , "-...." , "--..." , "---.." , "----." , ".-.-.-" ,
    "--..--" , "..--.." , ".----." , "-.-.--" , "-..-." , "-.--." , "-.--.-" , ".-..." } ;

    char *Returned_String = new char[200];
    int Returned_string_index = 0 ;
    char *temp_morse_code_holder = new char [7];
    int temp_morse_code_index = 0 , sequence_index = 0 ;
    while ( sequence [sequence_index] != '\0' )
    {
        if ( sequence [sequence_index] == ' ')
        {
            int size = 0 ;
            while ( temp_morse_code_holder[size] != '\0' )
            {
                size ++ ;
            }
            for ( int i = 0 ; i < 45 ; i++ )
            {
                for (int j = 0 ; morse_character_code [i][j] != '\0' && temp_morse_code_holder[j] != '\0' ; j++ )
                {
                    if ( morse_character_code [i][j] == temp_morse_code_holder [j] )
                    {
                        size -- ;
                    }
                }
                if ( !size )
                {
                    Returned_String [Returned_string_index] = Alphabets_Letters [i] ;
                    Returned_String ++ ;
                }
            }
            for ( int a = 0 ; temp_morse_code_holder [a] != '\0' ; a++ )
            {
                temp_morse_code_holder [a] = '\0' ;
            }
            temp_morse_code_index = 0 ;
        }
        if ( sequence [sequence_index] == '/' )
        {
            Returned_String [Returned_string_index] = ' ' ;
            Returned_string_index ++ ;
        }
        temp_morse_code_holder [temp_morse_code_index] = sequence [sequence_index] ;
        temp_morse_code_index ++ ;
        sequence_index ++ ;
    }
    delete []temp_morse_code_holder ;
    return Returned_String ;
}
