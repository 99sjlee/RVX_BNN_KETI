set PROJECT_NAME managed_ip_project
create_project ${PROJECT_NAME} ./${PROJECT_NAME} -part xcku19p-ffvj1760-3-e -ip

set files [glob ./xci/*/*.{xci,xcix}]
add_files -norecurse $files
close_project
