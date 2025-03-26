#include <fcntl.h>
#include <linux/kd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

// Función para hacer sonar una nota con una frecuencia y duración
void beep(int frecuencia, int duracion) {
  int console_fd = open("/dev/console", O_WRONLY);
  if (console_fd == -1) {
    perror("Error abriendo la consola. Prueba ejecutarlo con sudo.");
    return;
  }

  ioctl(console_fd, KIOCSOUND, (int)(1193180 / frecuencia));
  usleep(duracion * 1000);         // Convertir a microsegundos
  ioctl(console_fd, KIOCSOUND, 0); // Apagar sonido

  close(console_fd);
}

int main() {
  printf("¡Reproduciendo una canción en PC Speaker!\n");

  beep(440, 300);
  usleep(100000); // Nota La
  beep(494, 300);
  usleep(100000); // Nota Si
  beep(523, 300);
  usleep(100000); // Nota Do
  beep(587, 500);
  usleep(200000); // Nota Re

  printf("¡Canción terminada!\n");
  return 0;
}
