#ifndef MAIN_H
#define MAIN_H

#include <gtk/gtk.h>
#include "jsmn.h"

#ifdef LAYERSHELL
#include <gtk-layer-shell/gtk-layer-shell.h>
#endif

// Type definitions and global variables here
typedef struct {
    char *label;
    char *action;
    char *text;
    float yalign;
    float xalign;
    guint bind;
    gboolean circular;
} button;

extern char *command;
extern char *layout_path;
extern char *css_path;
extern button *buttons;
extern GtkWidget *gtk_window;
extern int num_buttons;
extern int buttons_per_row;
extern int margin[];
extern int space[];
extern gboolean protocol;

gboolean process_args(int argc, char *argv[]);
gboolean get_layout_path();
gboolean get_css_path();
GtkWidget *get_window();
char *get_substring(char *s, int start, int end, char *buf);
void execute(GtkWidget *widget, char *action);
gboolean check_key(GtkWidget *widget, GdkEventKey *event, gpointer data);
void load_css();

gboolean get_buttons(FILE *json);
void load_buttons(GtkWindow *window);

#endif // MAIN_H
