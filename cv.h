#ifndef CV_H
# define CV_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* ========== STRUCTURES ========== */

typedef struct s_skill
{
	char				*name;
	struct s_skill		*next;
}	t_skill;

typedef struct s_competencias
{
	t_skill		*lenguajes;
	t_skill		*herramientas;
	t_skill		*sistemas;
	t_skill		*competencias_tecnicas;
	t_skill		*idiomas;
}	t_competencias;

typedef struct s_proyecto
{
	char				*titulo;
	char				*lugar;
	char				*descripcion;
	t_skill				*tecnologias;
	struct s_proyecto	*next;
}	t_proyecto;

typedef struct s_formacion
{
	char				*titulo;
	char				*institucion;
	char				*ubicacion;
	char				*fecha_inicio;
	char				*fecha_fin;
	char				*descripcion;
	struct s_formacion	*next;
}	t_formacion;

typedef struct s_experiencia
{
	char					*puesto;
	char					*empresa;
	char					*ubicacion;
	char					*fecha_inicio;
	char					*fecha_fin;
	t_skill					*responsabilidades;
	struct s_experiencia	*next;
}	t_experiencia;

typedef struct s_cv
{
	char			*nombre;
	char			*ubicacion;
	char			*email;
	char			*telefono;
	char			*perfil;
	t_competencias	*competencias;
	t_proyecto		*proyectos;
	t_formacion		*formacion;
	t_experiencia	*experiencia;
}	t_cv;

/* ========== PROTOTIPOS ========== */

// Funciones de creación
t_skill			*skill_new(char *name);
void			skill_add_back(t_skill **lst, t_skill *new);
t_competencias	*competencias_init(void);
t_proyecto		*proyecto_new(char *titulo, char *lugar, char *descripcion);
t_formacion		*formacion_new(char *titulo, char *institucion, char *ubicacion,
					char *inicio, char *fin, char *descripcion);
t_experiencia	*experiencia_new(char *puesto, char *empresa, char *ubicacion,
					char *inicio, char *fin);
t_cv			*cv_init(void);

// Funciones de añadir elementos
void			add_proyecto(t_cv *cv, t_proyecto *proyecto);
void			add_formacion(t_cv *cv, t_formacion *formacion);
void			add_experiencia(t_cv *cv, t_experiencia *exp);

// Funciones de display
void			print_header(t_cv *cv);
void			print_perfil(t_cv *cv);
void			print_competencias(t_competencias *comp);
void			print_proyectos(t_proyecto *proyectos);
void			print_formacion(t_formacion *formacion);
void			print_experiencia(t_experiencia *exp);

// Menu interactivo
void			run_menu(t_cv *cv);

// Funciones de liberación de memoria
void			free_skills(t_skill *skills);
void			free_competencias(t_competencias *comp);
void			free_proyectos(t_proyecto *proyectos);
void			free_formacion(t_formacion *formacion);
void			free_experiencia(t_experiencia *exp);
void			free_cv(t_cv *cv);

#endif
