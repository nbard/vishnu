link_directories(${Boost_LIBRARY_DIRS}
  ${FMS_CLI_SOURCE_DIR}
  ${CLI_SOURCE_DIR}
  ${LIBRARY_OUTPUT_PATH}
  )

include_directories(${Boost_INCLUDE_DIRS}
  ${FMS_EMF_DATA_DIR}
  ${FMS_DATA_DIR}
  ${EMF4CPP_INCLUDE_DIR}
  ${FMS_API_SOURCE_DIR}
  ${FMS_CLIENT_PROXY_SOURCE_DIR}
  ${VISHNU_EXCEPTION_INCLUDE_DIR}
  ${FMS_CLI_SOURCE_DIR}
  ${UTILVISHNU_SOURCE_DIR}
  ${UMS_API_SOURCE_DIR}
  ${CLIENT_PROXY_SOURCE_DIR}
  ${EMF_DATA_DIR}
  ${UMS_DATA_DIR}
  )

#declare all command lines provided

set(ALLCLI 
  head
  stat
  tail
  touch
  mkdir
  rm
  rmdir
  chgrp
  chmod
  cat
  ls
  cp
  acp
  mv
  amv
  stop_file_transfer
  list_file_transfers
  )

#set the prefix of command
set(CMDPREFIX vishnu_)

# macro to generate all command lines

macro(genCli NAME )

  set(source_files ${NAME} cmdArgs.cpp FMSDisplayer.cpp)

  set(CMDNAME ${CMDPREFIX}${NAME})

  #Configuration de l'executable
  add_executable (${CMDNAME}
    ${source_files}
    )

  #Configuration de l'edition de liens
  target_link_libraries(${CMDNAME}
    ${Boost_LIBRARIES}
    ${VISHNU_EXCEPTION_LIB}
    vishnu-fms-client
)
  install(TARGETS ${CMDNAME} DESTINATION ${BIN_INSTALL_DIR})
endmacro(genCli)

#Loop over all command lines to generate them
foreach(cli ${ALLCLI})
  genCli(${cli})
endforeach(cli)


