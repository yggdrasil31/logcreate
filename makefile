##############################################################################
# HEAD : (c) ACTIA 2015 : " Any copie and re-utilisation of this file without
#                           the written consent of ACTIA is forbidden "
#        --------------------------------------------------------------------
#        Classification :  (-)No   (X)Confident. ACTIA   (-)Confident. Client
#        --------------------------------------------------------------------
#        logcreate : create a log from a template and a loop counter
##############################################################################
# FILE : makefile
#-----------------------------------------------------------------------------
# DESC : defining how to build logcreate
#-----------------------------------------------------------------------------  
# HIST : Version |   Date   | Author | Description
#         01.00  | 09/04/18 |  JTou  | Creation of this file
#                |          |        |
##############################################################################
 
# Comment/uncomment the following line to disable/enable debugging
#DEBUG=y
ifeq ($(DEBUG),y)
	EXTRA_CFLAGS =-DDEBUG
else
	EXTRA_CFLAGS =
endif

# List of files to compile
LOGCREATE_TARGET=logCreate
LOGCREATE_SRCS=main.c
LOGCREATE_OBJS=$(LOGCREATE_SRCS:.c=.o)


# Include folder
INC=-I./inc

# Libs folder
LDLIBS=

# CFlags
CFLAGS +=
EXTRA_CFLAGS+=


# Pattern rule to generate .o out of .c
%.o: %.c
	$(CC) $(INC) $(CFLAGS) $(EXTRA_CFLAGS) -fPIC -c -o $@ $<

# Pattern rule to generate .o out of .cpp
%.o: %.cpp
	$(CXX) $(INC) $(CFLAGS) $(EXTRA_CFLAGS) -c -o $@ $<


# Target definition
all: $(LOGCREATE_TARGET)


clean:
	rm -f $(LOGCREATE_OBS) $(LOGCREATE_TARGET)
	

$(LOGCREATE_TARGET): $(LOGCREATE_OBJS)
	@echo Building $(LOGCREATE_TARGET)
	$(CC) -o $@ $(LOGCREATE_OBJS) -Wl,-Map=$(LOGCREATE_TARGET).map

# DO NOT DELETE THIS LINE -- make depend needs it
