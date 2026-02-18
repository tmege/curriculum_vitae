#include "cv.h"

void	free_skills(t_skill *skills)
{
	t_skill	*tmp;

	while (skills)
	{
		tmp = skills;
		skills = skills->next;
		free(tmp->name);
		free(tmp);
	}
}

void	free_competencias(t_competencias *comp)
{
	if (!comp)
		return ;
	free_skills(comp->lenguajes);
	free_skills(comp->herramientas);
	free_skills(comp->sistemas);
	free_skills(comp->competencias_tecnicas);
	free_skills(comp->idiomas);
	free(comp);
}

void	free_proyectos(t_proyecto *proyectos)
{
	t_proyecto	*tmp;

	while (proyectos)
	{
		tmp = proyectos;
		proyectos = proyectos->next;
		free(tmp->titulo);
		free(tmp->lugar);
		free(tmp->descripcion);
		free_skills(tmp->tecnologias);
		free(tmp);
	}
}

void	free_formacion(t_formacion *formacion)
{
	t_formacion	*tmp;

	while (formacion)
	{
		tmp = formacion;
		formacion = formacion->next;
		free(tmp->titulo);
		free(tmp->institucion);
		free(tmp->ubicacion);
		free(tmp->fecha_inicio);
		free(tmp->fecha_fin);
		free(tmp->descripcion);
		free(tmp);
	}
}

void	free_experiencia(t_experiencia *exp)
{
	t_experiencia	*tmp;

	while (exp)
	{
		tmp = exp;
		exp = exp->next;
		free(tmp->puesto);
		free(tmp->empresa);
		free(tmp->ubicacion);
		free(tmp->fecha_inicio);
		free(tmp->fecha_fin);
		free_skills(tmp->responsabilidades);
		free(tmp);
	}
}

void	free_cv(t_cv *cv)
{
	if (!cv)
		return ;
	free(cv->nombre);
	free(cv->ubicacion);
	free(cv->email);
	free(cv->telefono);
	free(cv->perfil);
	free_competencias(cv->competencias);
	free_proyectos(cv->proyectos);
	free_formacion(cv->formacion);
	free_experiencia(cv->experiencia);
	free(cv);
}
