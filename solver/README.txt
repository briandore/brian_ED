FALTA VERIFICAR SI LOS METODOS SON EFICIENTE
PARA ELLO ES MEJOR HACER FUNCIONAR LA LISTA QUE TENGO
 IDEAS PARA CAMBIAR LA myList CON ALGO ASI
    QHash<QString raiz, QList l>lista_words
    la raiz puede ser de 2 o 3 letras y dentro de l agregar el complemento ejemplo

 add(QString word){
        verificar si la palabra esta en la lista sino agregar la
        lista_words[word.left(2)].push_back(word.mid(3));
        }
