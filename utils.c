#include "cv.h"

/* ========== SKILL LIST FUNCTIONS ========== */

t_skill	*skill_new(char *name)
{
	t_skill	*new;

	new = (t_skill *)malloc(sizeof(t_skill));
	if (!new)
		return (NULL);
	new->name = strdup(name);
	new->next = NULL;
	return (new);
}

void	skill_add_back(t_skill **lst, t_skill *new)
{
	t_skill	*current;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

/* ========== INIT FUNCTIONS ========== */

t_competencias	*competencias_init(void)
{
	t_competencias	*comp;

	comp = (t_competencias *)malloc(sizeof(t_competencias));
	if (!comp)
		return (NULL);
	comp->lenguajes = NULL;
	comp->herramientas = NULL;
	comp->sistemas = NULL;
	comp->competencias_tecnicas = NULL;
	comp->idiomas = NULL;
	return (comp);
}

t_proyecto	*proyecto_new(char *titulo, char *lugar, char *descripcion)
{
	t_proyecto	*new;

	new = (t_proyecto *)malloc(sizeof(t_proyecto));
	if (!new)
		return (NULL);
	new->titulo = strdup(titulo);
	new->lugar = strdup(lugar);
	new->descripcion = strdup(descripcion);
	new->tecnologias = NULL;
	new->next = NULL;
	return (new);
}

t_formacion	*formacion_new(char *titulo, char *institucion, char *ubicacion,
				char *inicio, char *fin, char *descripcion)
{
	t_formacion	*new;

	new = (t_formacion *)malloc(sizeof(t_formacion));
	if (!new)
		return (NULL);
	new->titulo = strdup(titulo);
	new->institucion = strdup(institucion);
	new->ubicacion = strdup(ubicacion);
	new->fecha_inicio = strdup(inicio);
	new->fecha_fin = strdup(fin);
	new->descripcion = strdup(descripcion);
	new->next = NULL;
	return (new);
}

t_experiencia	*experiencia_new(char *puesto, char *empresa, char *ubicacion,
					char *inicio, char *fin)
{
	t_experiencia	*new;

	new = (t_experiencia *)malloc(sizeof(t_experiencia));
	if (!new)
		return (NULL);
	new->puesto = strdup(puesto);
	new->empresa = strdup(empresa);
	new->ubicacion = strdup(ubicacion);
	new->fecha_inicio = strdup(inicio);
	new->fecha_fin = strdup(fin);
	new->responsabilidades = NULL;
	new->next = NULL;
	return (new);
}

t_cv	*cv_init(void)
{
	t_cv	*cv;

	cv = (t_cv *)malloc(sizeof(t_cv));
	if (!cv)
		return (NULL);
	cv->nombre = NULL;
	cv->ubicacion = NULL;
	cv->email = NULL;
	cv->telefono = NULL;
	cv->perfil = NULL;
	cv->competencias = NULL;
	cv->proyectos = NULL;
	cv->formacion = NULL;
	cv->experiencia = NULL;
	return (cv);
}

/* ========== ADD FUNCTIONS ========== */

void	add_proyecto(t_cv *cv, t_proyecto *proyecto)
{
	t_proyecto	*current;

	if (!cv || !proyecto)
		return ;
	if (!cv->proyectos)
	{
		cv->proyectos = proyecto;
		return ;
	}
	current = cv->proyectos;
	while (current->next)
		current = current->next;
	current->next = proyecto;
}

void	add_formacion(t_cv *cv, t_formacion *formacion)
{
	t_formacion	*current;

	if (!cv || !formacion)
		return ;
	if (!cv->formacion)
	{
		cv->formacion = formacion;
		return ;
	}
	current = cv->formacion;
	while (current->next)
		current = current->next;
	current->next = formacion;
}

void	add_experiencia(t_cv *cv, t_experiencia *exp)
{
	t_experiencia	*current;

	if (!cv || !exp)
		return ;
	if (!cv->experiencia)
	{
		cv->experiencia = exp;
		return ;
	}
	current = cv->experiencia;
	while (current->next)
		current = current->next;
	current->next = exp;
}
