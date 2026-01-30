#include "cv.h"

/* ========== PRINT HELPERS ========== */

static void	print_skill_list(t_skill *skills)
{
	while (skills)
	{
		printf("  • %s\n", skills->name);
		skills = skills->next;
	}
}

static void	print_separator(void)
{
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}

/* ========== PRINT FUNCTIONS ========== */

void	print_competencias(t_competencias *comp)
{
	if (!comp)
		return ;
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║              COMPETENCIAS TÉCNICAS                               ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
	
	if (comp->lenguajes)
	{
		printf("Lenguajes:\n");
		print_skill_list(comp->lenguajes);
		printf("\n");
	}
	if (comp->herramientas)
	{
		printf("Herramientas:\n");
		print_skill_list(comp->herramientas);
		printf("\n");
	}
	if (comp->sistemas)
	{
		printf("Sistemas:\n");
		print_skill_list(comp->sistemas);
		printf("\n");
	}
	if (comp->competencias_tecnicas)
	{
		printf("Competencias técnicas:\n");
		print_skill_list(comp->competencias_tecnicas);
		printf("\n");
	}
	if (comp->idiomas)
	{
		printf("Idiomas:\n");
		print_skill_list(comp->idiomas);
	}
}

void	print_proyectos(t_proyecto *proyectos)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║         PROYECTOS Y EXPERIENCIA EN DESARROLLO                    ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
	
	while (proyectos)
	{
		printf("▸ %s\n", proyectos->titulo);
		printf("  %s\n\n", proyectos->lugar);
		printf("  %s\n", proyectos->descripcion);
		
		if (proyectos->tecnologias)
		{
			printf("\n  Tecnologías utilizadas:\n");
			print_skill_list(proyectos->tecnologias);
		}
		
		if (proyectos->next)
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
		proyectos = proyectos->next;
	}
}

void	print_formacion(t_formacion *formacion)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                    FORMACIÓN Y DIPLOMAS                          ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
	
	while (formacion)
	{
		printf("▸ %s\n", formacion->titulo);
		printf("  %s, %s\n", formacion->institucion, formacion->ubicacion);
		printf("  %s - %s\n", formacion->fecha_inicio, formacion->fecha_fin);
		if (formacion->descripcion && strlen(formacion->descripcion) > 0)
			printf("  %s\n", formacion->descripcion);
		
		if (formacion->next)
			printf("\n");
		formacion = formacion->next;
	}
}

void	print_experiencia(t_experiencia *exp)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                  EXPERIENCIA PROFESIONAL                         ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
	
	while (exp)
	{
		printf("▸ %s\n", exp->puesto);
		printf("  %s, %s\n", exp->empresa, exp->ubicacion);
		printf("  %s - %s\n\n", exp->fecha_inicio, exp->fecha_fin);
		
		if (exp->responsabilidades)
		{
			printf("  Responsabilidades:\n");
			print_skill_list(exp->responsabilidades);
		}
		
		if (exp->next)
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
		exp = exp->next;
	}
}

void	print_cv(t_cv *cv)
{
	if (!cv)
		return ;
	
	// Header
	printf("\n");
	printf("████████████████████████████████████████████████████████████████████\n");
	printf("██                                                                ██\n");
	printf("██                         %s                          ██\n", cv->nombre);
	printf("██                                                                ██\n");
	printf("████████████████████████████████████████████████████████████████████\n");
	printf("\n");
	printf("📍 %s  |  📧 %s  |  📞 %s\n", cv->ubicacion, cv->email, cv->telefono);
	print_separator();
	
	// Perfil
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                     PERFIL PROFESIONAL                           ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
	printf("%s\n", cv->perfil);
	print_separator();
	
	// Sections
	if (cv->competencias)
	{
		print_competencias(cv->competencias);
		print_separator();
	}
	if (cv->proyectos)
	{
		print_proyectos(cv->proyectos);
		print_separator();
	}
	if (cv->formacion)
	{
		print_formacion(cv->formacion);
		print_separator();
	}
	if (cv->experiencia)
	{
		print_experiencia(cv->experiencia);
		print_separator();
	}
	
	printf("/* TODO: recrutar_talento(este_candidato); */\n\n");
}
