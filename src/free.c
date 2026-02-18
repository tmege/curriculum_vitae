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

void	free_competencies(t_competencies *comp)
{
	if (!comp)
		return ;
	free_skills(comp->languages);
	free_skills(comp->tools);
	free_skills(comp->systems);
	free_skills(comp->technical_skills);
	free_skills(comp->spoken_languages);
	free(comp);
}

void	free_projects(t_project *projects)
{
	t_project	*tmp;

	while (projects)
	{
		tmp = projects;
		projects = projects->next;
		free(tmp->title);
		free(tmp->location);
		free(tmp->description);
		free_skills(tmp->technologies);
		free(tmp);
	}
}

void	free_education(t_education *education)
{
	t_education	*tmp;

	while (education)
	{
		tmp = education;
		education = education->next;
		free(tmp->title);
		free(tmp->institution);
		free(tmp->location);
		free(tmp->start_date);
		free(tmp->end_date);
		free(tmp->description);
		free(tmp);
	}
}

void	free_experience(t_experience *exp)
{
	t_experience	*tmp;

	while (exp)
	{
		tmp = exp;
		exp = exp->next;
		free(tmp->position);
		free(tmp->company);
		free(tmp->location);
		free(tmp->start_date);
		free(tmp->end_date);
		free_skills(tmp->responsibilities);
		free(tmp);
	}
}

void	free_cv(t_cv *cv)
{
	if (!cv)
		return ;
	free(cv->name);
	free(cv->title);
	free(cv->location);
	free(cv->email);
	free(cv->phone);
	free(cv->github);
	free(cv->profile);
	free_competencies(cv->competencies);
	free_projects(cv->projects);
	free_education(cv->education);
	free_experience(cv->experience);
	free(cv);
}
