               //Indentificar a posição da letra index da chave no alfabeto
                for (counter = 0; initialLetter != charKey[ck]; counter++)
                {
                    if ( (charKey[ck]  >= 'a') && (charKey[ck]  <= 'z') )
                    {
                        initialLetter = 'a';
                    }
                    else if ( (charKey[ck]  >= 'A') && (charKey[ck]  <= 'Z') )
                    {
                        initialLetter = 'A';
                    }


                    initialLetter = initialLetter + counter;

                }

                counter = counter - 1;

                //Eu preciso descobrir o indice de text no alfabeto ai eu preciso verificar na chave quem representa o indece e substitui

                        //Criptografar usando o numero do indixe indentificado
                        if ( (text[ck]  >= 'a') && (text[ck]  <= 'z') )
                        {
                            text[ck] = 'a';
                            text[ck] = text[ck] + counter;
                        }
                        else if( (text[ck]  >= 'A') && (text[ck]  <= 'Z') )
                        {
                            text[ck] = 'A';
                            text[ck] = text[ck] + counter;
                        }

            }