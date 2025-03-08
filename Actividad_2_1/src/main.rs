//Ruiz Hernandez Oscar Alejandro 218419696

fn main() {
    let n: usize = 5;
    
    //Crear un vector dinámico (equivalente a malloc en C)
    let mut arr = vec![0; n];

    //Llenar el vector con valores
    for i in 0..n {
        arr[i] = i * 10;
    }

    //Mostrar valores antes de liberar la memoria
    println!("Valores almacenados: {:?}", arr);

    /*  
    ERROR EVITADO: No podemos acceder a memoria liberada en Rust
    Rust libera la memoria automáticamente cuando arr sale de su scope
    No es necesario llamar a `free()`, Rust se encarga de la memoria automáticamente
    */
}

/* ejemplo de use-after-free 
fn main() {
    let arr = vec![1, 2, 3, 4, 5];

    drop(arr); // Libera la memoria

    ERROR en compilación: "use of moved value"
    println!("{}", arr[0]); // 
}
*/