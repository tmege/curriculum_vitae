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

typedef struct s_competencies
{
	t_skill		*languages;
	t_skill		*tools;
	t_skill		*systems;
	t_skill		*technical_skills;
	t_skill		*spoken_languages;
}	t_competencies;

typedef struct s_project
{
	char				*title;
	char				*location;
	char				*description;
	t_skill				*technologies;
	struct s_project	*next;
}	t_project;

typedef struct s_education
{
	char				*title;
	char				*institution;
	char				*location;
	char				*start_date;
	char				*end_date;
	char				*description;
	struct s_education	*next;
}	t_education;

typedef struct s_experience
{
	char					*position;
	char					*company;
	char					*location;
	char					*start_date;
	char					*end_date;
	t_skill					*responsibilities;
	struct s_experience		*next;
}	t_experience;

typedef struct s_cv
{
	char			*name;
	char			*title;
	char			*location;
	char			*email;
	char			*phone;
	char			*github;
	char			*profile;
	t_competencies	*competencies;
	t_project		*projects;
	t_education		*education;
	t_experience	*experience;
}	t_cv;

/* ========== PROTOTYPES ========== */

// Creation functions
t_skill			*skill_new(char *name);
void			skill_add_back(t_skill **lst, t_skill *new);
t_competencies	*competencies_init(void);
t_project		*project_new(char *title, char *location, char *description);
t_education		*education_new(char *title, char *institution, char *location,
					char *start, char *end, char *description);
t_experience	*experience_new(char *position, char *company, char *location,
					char *start, char *end);
t_cv			*cv_init(void);

// Add functions
void			add_project(t_cv *cv, t_project *project);
void			add_education(t_cv *cv, t_education *edu);
void			add_experience(t_cv *cv, t_experience *exp);

// Display functions
void			print_header(t_cv *cv);
void			print_profile(t_cv *cv);
void			print_competencies(t_competencies *comp);
void			print_projects(t_project *projects);
void			print_education(t_education *education);
void			print_experience(t_experience *exp);

// Interactive menu
void			run_menu(t_cv *cv);

// Memory free functions
void			free_skills(t_skill *skills);
void			free_competencies(t_competencies *comp);
void			free_projects(t_project *projects);
void			free_education(t_education *education);
void			free_experience(t_experience *exp);
void			free_cv(t_cv *cv);

#endif
