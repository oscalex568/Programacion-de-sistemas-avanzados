use std::sync::{Arc, Mutex};
use std::thread;

const NUM_HILOS: usize = 5;
const ITERACIONES: usize = 1_000_000;

fn main() {
    let variable_compartida = Arc::new(Mutex::new(0)); // Variable protegida con Arc y Mutex
    let mut handles = vec![];

    for _ in 0..NUM_HILOS {
        let variable_compartida = Arc::clone(&variable_compartida); // Clonar el Arc para compartir entre hilos

        let handle = thread::spawn(move || {
            for _ in 0..ITERACIONES {
                let mut valor = variable_compartida.lock().unwrap(); // Bloqueo del mutex
                *valor += 1; // Incremento de la variable
            }
        });

        handles.push(handle);
    }

    // Esperar a que todos los hilos terminen
    for handle in handles {
        handle.join().unwrap();
    }

    println!(
        "Valor final de variable_compartida: {}",
        *variable_compartida.lock().unwrap()
    );
}
