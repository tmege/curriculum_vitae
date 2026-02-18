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

t_competencies	*competencies_init(void)
{
	t_competencies	*comp;

	comp = (t_competencies *)malloc(sizeof(t_competencies));
	if (!comp)
		return (NULL);
	comp->languages = NULL;
	comp->tools = NULL;
	comp->systems = NULL;
	comp->technical_skills = NULL;
	comp->spoken_languages = NULL;
	return (comp);
}

t_project	*project_new(char *title, char *location, char *description)
{
	t_project	*new;

	new = (t_project *)malloc(sizeof(t_project));
	if (!new)
		return (NULL);
	new->title = strdup(title);
	new->location = strdup(location);
	new->description = strdup(description);
	new->technologies = NULL;
	new->next = NULL;
	return (new);
}

t_education	*education_new(char *title, char *institution, char *location,
				char *start, char *end, char *description)
{
	t_education	*new;

	new = (t_education *)malloc(sizeof(t_education));
	if (!new)
		return (NULL);
	new->title = strdup(title);
	new->institution = strdup(institution);
	new->location = strdup(location);
	new->start_date = strdup(start);
	new->end_date = strdup(end);
	new->description = strdup(description);
	new->next = NULL;
	return (new);
}

t_experience	*experience_new(char *position, char *company, char *location,
					char *start, char *end)
{
	t_experience	*new;

	new = (t_experience *)malloc(sizeof(t_experience));
	if (!new)
		return (NULL);
	new->position = strdup(position);
	new->company = strdup(company);
	new->location = strdup(location);
	new->start_date = strdup(start);
	new->end_date = strdup(end);
	new->responsibilities = NULL;
	new->next = NULL;
	return (new);
}

t_cv	*cv_init(void)
{
	t_cv	*cv;

	cv = (t_cv *)malloc(sizeof(t_cv));
	if (!cv)
		return (NULL);
	cv->name = NULL;
	cv->title = NULL;
	cv->location = NULL;
	cv->email = NULL;
	cv->phone = NULL;
	cv->github = NULL;
	cv->profile = NULL;
	cv->competencies = NULL;
	cv->projects = NULL;
	cv->education = NULL;
	cv->experience = NULL;
	return (cv);
}

/* ========== ADD FUNCTIONS ========== */

void	add_project(t_cv *cv, t_project *project)
{
	t_project	*current;

	if (!cv || !project)
		return ;
	if (!cv->projects)
	{
		cv->projects = project;
		return ;
	}
	current = cv->projects;
	while (current->next)
		current = current->next;
	current->next = project;
}

void	add_education(t_cv *cv, t_education *edu)
{
	t_education	*current;

	if (!cv || !edu)
		return ;
	if (!cv->education)
	{
		cv->education = edu;
		return ;
	}
	current = cv->education;
	while (current->next)
		current = current->next;
	current->next = edu;
}

void	add_experience(t_cv *cv, t_experience *exp)
{
	t_experience	*current;

	if (!cv || !exp)
		return ;
	if (!cv->experience)
	{
		cv->experience = exp;
		return ;
	}
	current = cv->experience;
	while (current->next)
		current = current->next;
	current->next = exp;
}
